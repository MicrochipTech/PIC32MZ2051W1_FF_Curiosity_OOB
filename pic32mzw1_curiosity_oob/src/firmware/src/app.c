/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

/*******************************************************************************
Copyright (C) 2021 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "app_commands.h"
#include <wolfssl/ssl.h>
#include <tcpip/src/hash_fnv.h>
#include "system/debug/sys_debug.h"
#include "system/ota/framework/ota_app/app_ota.h"
#include "configuration.h"
#include "definitions.h"

APP_TASK_STATES App_state;
uint8_t app_mode = APP_NONE;

void APP_SetMode(uint8_t mode)
{
    app_mode = mode;
    App_state = APP_TRIGGER_OTA;   
}

uint8_t APP_GetMode(void)
{
    return app_mode;
}
void APP_Initialize(void) {
    APP_Commands_Init();
    ota_app_reg_cb();
    app_mode = APP_CLOUD;
    App_state = APP_INIT;
}

void APP_Tasks(void) {
    switch(App_state)
    {
        case APP_INIT:
        {
            if(app_mode == APP_CLOUD)
            {
                App_state = APP_IDLE;
            }
            else if(app_mode == APP_OTA)
            {
                SYS_CONSOLE_PRINT("INIT OTA\r\n");
                App_state = APP_TRIGGER_OTA;
            }
            break;
        }  
        case APP_IDLE:
        {
           break; 
        }
        case APP_TRIGGER_OTA:
        {

			SYS_MQTT_Deinitialize();
            if (SYS_OTA_SUCCESS == SYS_OTA_CtrlMsg(SYS_OTA_UPDATECHCK, NULL, 0)) {
            } else {
                break;
            }
            App_state = APP_IDLE;

            break;
        }

    }
    
    return;
}
/*******************************************************************************
 End of File
 */


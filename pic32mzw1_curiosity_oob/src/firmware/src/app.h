/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "configuration.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
#define APP_VERSION "WFI32E04_CURIOSITY_1.0.0"
typedef enum { 
    APP_IDLE = 0,
   
    APP_INIT,

    APP_TRIGGER_OTA
}APP_TASK_STATES;   

enum{
    APP_NONE = 0,
    APP_CLOUD,
    APP_OTA
};
void APP_Initialize ( void );
void APP_Tasks ( void );

void APP_SetMode(uint8_t mode);
uint8_t APP_GetMode(void);
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* _APP_H */

/*******************************************************************************
 End of File
 */


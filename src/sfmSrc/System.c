/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-06-29
* Description: System configurations
***************************************************************************************************/

#include "mpc5643l.h"
#include "sysclk_init.h"
#include "siu_init.h"
#include "System.h"

/*-----------------------------------------------------------*/
/*        FCCU CF Key Register (FCCU_CFK)                    */
/*-----------------------------------------------------------*/
#define FCCU_CFK_Key                   0x618B7A50                /* Critical fault key */

/*-----------------------------------------------------------*/
/*        FCCU NCF Key Register (FCCU_NCFK)                  */
/*-----------------------------------------------------------*/
#define FCCU_NCFK_Key                  0xAB3498FE                /* Non-Critical fault key */

void SYS_init(void)
{
    {
        uint32_t i;
        uint32_t a[4];
        for (i=0;i<4;i++)
        {
            FCCU.CFK.R = FCCU_CFK_Key;
            FCCU.CF_S[i].R = 0xFFFFFFFF;
            while (FCCU.CTRL.B.OPS != 0x03) ;/* wait for the completion of the operation */
            a[i]= FCCU.CF_S[i].R;
            (void) a;
        }
    }

    {
        uint32_t i;
        uint32_t b[4];
        for (i=0;i<4;i++)
        {
            FCCU.NCFK.R = FCCU_NCFK_Key;
            FCCU.NCF_S[i].R = 0xFFFFFFFF;
            while (FCCU.CTRL.B.OPS != 0x03) ;/* wait for the completion of the operation */
            b[i]= FCCU.NCF_S[i].R;
            (void) b;
        }
    }

  /* ----------------------------------------------------------- */
  /*                   System Initialization Functions              */
  /* ----------------------------------------------------------- */

  /* ----------------------------------------------------------- */
  /*                  Reset Determination Goes Here             */
  /* ----------------------------------------------------------- */

  /* ----------------------------------------------------------- */
  /*            Initialize the System Clock, Mode Entry (ME) & CMU             */
  /* ----------------------------------------------------------- */
  sysclk_module_init_fnc();

  /* ----------------------------------------------------------- */
  /*            Initialize the Mode Entry Post Configuration             */
  /* ----------------------------------------------------------- */
  mode_entry_post_config_fnc();
  siu_init_fnc();
}

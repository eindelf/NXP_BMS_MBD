/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "BMU_Driver.h"
#include "DMA.h"

/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width                        1

/*
 * Create external references here.
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void SPIRead_Outputs_wrapper(uint32_T *Vc1,
  uint32_T *Vc2,
  uint32_T *Vc3,
  uint32_T *PEC)
{
  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  /* This sample sets the output equal to the input
     y0[0] = u0[0];
     For complex signals use: y0[0].re = u0[0].re;
     y0[0].im = u0[0].im;
     y1[0].re = u1[0].re;
     y1[0].im = u1[0].im;
   */
  SPI_Read_Master_Onecell(Vc1);

  //SPI_Read_Master_Onecell(Vc2);
  //SPI_Read_Master_Onecell(Vc3);
  //SPI_Read_Master_PEC(PEC);
  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

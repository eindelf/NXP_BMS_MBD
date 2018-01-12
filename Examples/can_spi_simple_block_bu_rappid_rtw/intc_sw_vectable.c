/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: intc_sw_vectable.c
 *
 * Code generated for Simulink model 'can_spi_simple_block_bu'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Wed Nov 29 13:29:53 2017
 *
 * Target selection: rappid564xl.tlc
 * Embedded hardware selection: Freescale->32-bit PowerPC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

/********************  Dependent Include files here **********************/
#include "rappid_ref.h"
#include "target.h"

/**********************  Function Prototype here *************************/
void interrupt_handler (void);
extern void LIN0_Rx_ISR_handler(void);
extern void PIT_Ch0_ISR(void);
extern void can0_buf4_7_isr(void);
extern void interrupt_handler(void);

/*************************** Pragma_1 Section **************************/
#pragma section data_type ".ivor4_vector_table" ".ivor4_vector_table"

uint32_t ISRVectorTable[] = {
  (uint32_t)&interrupt_handler,        /* ISR 00 */
  (uint32_t)&interrupt_handler,        /* ISR 01 */
  (uint32_t)&interrupt_handler,        /* ISR 02 */
  (uint32_t)&interrupt_handler,        /* ISR 03 */
  (uint32_t)&interrupt_handler,        /* ISR 04 */
  (uint32_t)&interrupt_handler,        /* ISR 05 */
  (uint32_t)&interrupt_handler,        /* ISR 06 */
  (uint32_t)&interrupt_handler,        /* ISR 07 */
  (uint32_t)&interrupt_handler,        /* ISR 08 */
  (uint32_t)&interrupt_handler,        /* ISR 09 */
  (uint32_t)&interrupt_handler,        /* ISR 10 */
  (uint32_t)&interrupt_handler,        /* ISR 11 */
  (uint32_t)&interrupt_handler,        /* ISR 12 */
  (uint32_t)&interrupt_handler,        /* ISR 13 */
  (uint32_t)&interrupt_handler,        /* ISR 14 */
  (uint32_t)&interrupt_handler,        /* ISR 15 */
  (uint32_t)&interrupt_handler,        /* ISR 16 */
  (uint32_t)&interrupt_handler,        /* ISR 17 */
  (uint32_t)&interrupt_handler,        /* ISR 18 */
  (uint32_t)&interrupt_handler,        /* ISR 19 */
  (uint32_t)&interrupt_handler,        /* ISR 20 */
  (uint32_t)&interrupt_handler,        /* ISR 21 */
  (uint32_t)&interrupt_handler,        /* ISR 22 */
  (uint32_t)&interrupt_handler,        /* ISR 23 */
  (uint32_t)&interrupt_handler,        /* ISR 24 */
  (uint32_t)&interrupt_handler,        /* ISR 25 */
  (uint32_t)&interrupt_handler,        /* ISR 26 */
  (uint32_t)&interrupt_handler,        /* ISR 27 */
  (uint32_t)&interrupt_handler,        /* ISR 28 */
  (uint32_t)&interrupt_handler,        /* ISR 29 */
  (uint32_t)&interrupt_handler,        /* ISR 30 */
  (uint32_t)&interrupt_handler,        /* ISR 31 */
  (uint32_t)&interrupt_handler,        /* ISR 32 */
  (uint32_t)&interrupt_handler,        /* ISR 33 */
  (uint32_t)&interrupt_handler,        /* ISR 34 */
  (uint32_t)&interrupt_handler,        /* ISR 35 */
  (uint32_t)&interrupt_handler,        /* ISR 36 */
  (uint32_t)&interrupt_handler,        /* ISR 37 */
  (uint32_t)&interrupt_handler,        /* ISR 38 */
  (uint32_t)&interrupt_handler,        /* ISR 39 */
  (uint32_t)&interrupt_handler,        /* ISR 40 */
  (uint32_t)&interrupt_handler,        /* ISR 41 */
  (uint32_t)&interrupt_handler,        /* ISR 42 */
  (uint32_t)&interrupt_handler,        /* ISR 43 */
  (uint32_t)&interrupt_handler,        /* ISR 44 */
  (uint32_t)&interrupt_handler,        /* ISR 45 */
  (uint32_t)&interrupt_handler,        /* ISR 46 */
  (uint32_t)&interrupt_handler,        /* ISR 47 */
  (uint32_t)&interrupt_handler,        /* ISR 48 */
  (uint32_t)&interrupt_handler,        /* ISR 49 */
  (uint32_t)&interrupt_handler,        /* ISR 50 */
  (uint32_t)&interrupt_handler,        /* ISR 51 */
  (uint32_t)&interrupt_handler,        /* ISR 52 */
  (uint32_t)&interrupt_handler,        /* ISR 53 */
  (uint32_t)&interrupt_handler,        /* ISR 54 */
  (uint32_t)&interrupt_handler,        /* ISR 55 */
  (uint32_t)&interrupt_handler,        /* ISR 56 */
  (uint32_t)&interrupt_handler,        /* ISR 57 */
  (uint32_t)&interrupt_handler,        /* ISR 58 */
  (uint32_t)&PIT_Ch0_ISR,              /* ISR 59 */
  (uint32_t)&interrupt_handler,        /* ISR 60 */
  (uint32_t)&interrupt_handler,        /* ISR 61 */
  (uint32_t)&interrupt_handler,        /* ISR 62 */
  (uint32_t)&interrupt_handler,        /* ISR 63 */
  (uint32_t)&interrupt_handler,        /* ISR 64 */
  (uint32_t)&interrupt_handler,        /* ISR 65 */
  (uint32_t)&interrupt_handler,        /* ISR 66 */
  (uint32_t)&interrupt_handler,        /* ISR 67 */
  (uint32_t)&interrupt_handler,        /* ISR 68 */
  (uint32_t)&can0_buf4_7_isr,          /* ISR 69 */
  (uint32_t)&interrupt_handler,        /* ISR 70 */
  (uint32_t)&interrupt_handler,        /* ISR 71 */
  (uint32_t)&interrupt_handler,        /* ISR 72 */
  (uint32_t)&interrupt_handler,        /* ISR 73 */
  (uint32_t)&interrupt_handler,        /* ISR 74 */
  (uint32_t)&interrupt_handler,        /* ISR 75 */
  (uint32_t)&interrupt_handler,        /* ISR 76 */
  (uint32_t)&interrupt_handler,        /* ISR 77 */
  (uint32_t)&interrupt_handler,        /* ISR 78 */
  (uint32_t)&interrupt_handler,        /* ISR 79 */
  (uint32_t)&interrupt_handler,        /* ISR 80 */
  (uint32_t)&interrupt_handler,        /* ISR 81 */
  (uint32_t)&interrupt_handler,        /* ISR 82 */
  (uint32_t)&interrupt_handler,        /* ISR 83 */
  (uint32_t)&interrupt_handler,        /* ISR 84 */
  (uint32_t)&interrupt_handler,        /* ISR 85 */
  (uint32_t)&interrupt_handler,        /* ISR 86 */
  (uint32_t)&interrupt_handler,        /* ISR 87 */
  (uint32_t)&interrupt_handler,        /* ISR 88 */
  (uint32_t)&interrupt_handler,        /* ISR 89 */
  (uint32_t)&interrupt_handler,        /* ISR 90 */
  (uint32_t)&interrupt_handler,        /* ISR 91 */
  (uint32_t)&interrupt_handler,        /* ISR 92 */
  (uint32_t)&interrupt_handler,        /* ISR 93 */
  (uint32_t)&interrupt_handler,        /* ISR 94 */
  (uint32_t)&interrupt_handler,        /* ISR 95 */
  (uint32_t)&interrupt_handler,        /* ISR 96 */
  (uint32_t)&interrupt_handler,        /* ISR 97 */
  (uint32_t)&interrupt_handler,        /* ISR 98 */
  (uint32_t)&interrupt_handler,        /* ISR 99 */
  (uint32_t)&interrupt_handler,        /* ISR 100 */
  (uint32_t)&interrupt_handler,        /* ISR 101 */
  (uint32_t)&interrupt_handler,        /* ISR 102 */
  (uint32_t)&interrupt_handler,        /* ISR 103 */
  (uint32_t)&interrupt_handler,        /* ISR 104 */
  (uint32_t)&interrupt_handler,        /* ISR 105 */
  (uint32_t)&interrupt_handler,        /* ISR 106 */
  (uint32_t)&interrupt_handler,        /* ISR 107 */
  (uint32_t)&interrupt_handler,        /* ISR 108 */
  (uint32_t)&interrupt_handler,        /* ISR 109 */
  (uint32_t)&interrupt_handler,        /* ISR 110 */
  (uint32_t)&interrupt_handler,        /* ISR 111 */
  (uint32_t)&interrupt_handler,        /* ISR 112 */
  (uint32_t)&interrupt_handler,        /* ISR 113 */
  (uint32_t)&interrupt_handler,        /* ISR 114 */
  (uint32_t)&interrupt_handler,        /* ISR 115 */
  (uint32_t)&interrupt_handler,        /* ISR 116 */
  (uint32_t)&interrupt_handler,        /* ISR 117 */
  (uint32_t)&interrupt_handler,        /* ISR 118 */
  (uint32_t)&interrupt_handler,        /* ISR 119 */
  (uint32_t)&interrupt_handler,        /* ISR 120 */
  (uint32_t)&interrupt_handler,        /* ISR 121 */
  (uint32_t)&interrupt_handler,        /* ISR 122 */
  (uint32_t)&interrupt_handler,        /* ISR 123 */
  (uint32_t)&interrupt_handler,        /* ISR 124 */
  (uint32_t)&interrupt_handler,        /* ISR 125 */
  (uint32_t)&interrupt_handler,        /* ISR 126 */
  (uint32_t)&interrupt_handler,        /* ISR 127 */
  (uint32_t)&interrupt_handler,        /* ISR 128 */
  (uint32_t)&interrupt_handler,        /* ISR 129 */
  (uint32_t)&interrupt_handler,        /* ISR 130 */
  (uint32_t)&interrupt_handler,        /* ISR 131 */
  (uint32_t)&interrupt_handler,        /* ISR 132 */
  (uint32_t)&interrupt_handler,        /* ISR 133 */
  (uint32_t)&interrupt_handler,        /* ISR 134 */
  (uint32_t)&interrupt_handler,        /* ISR 135 */
  (uint32_t)&interrupt_handler,        /* ISR 136 */
  (uint32_t)&interrupt_handler,        /* ISR 137 */
  (uint32_t)&interrupt_handler,        /* ISR 138 */
  (uint32_t)&interrupt_handler,        /* ISR 139 */
  (uint32_t)&interrupt_handler,        /* ISR 140 */
  (uint32_t)&interrupt_handler,        /* ISR 141 */
  (uint32_t)&interrupt_handler,        /* ISR 142 */
  (uint32_t)&interrupt_handler,        /* ISR 143 */
  (uint32_t)&interrupt_handler,        /* ISR 144 */
  (uint32_t)&interrupt_handler,        /* ISR 145 */
  (uint32_t)&interrupt_handler,        /* ISR 146 */
  (uint32_t)&interrupt_handler,        /* ISR 147 */
  (uint32_t)&interrupt_handler,        /* ISR 148 */
  (uint32_t)&interrupt_handler,        /* ISR 149 */
  (uint32_t)&interrupt_handler,        /* ISR 150 */
  (uint32_t)&interrupt_handler,        /* ISR 151 */
  (uint32_t)&interrupt_handler,        /* ISR 152 */
  (uint32_t)&interrupt_handler,        /* ISR 153 */
  (uint32_t)&interrupt_handler,        /* ISR 154 */
  (uint32_t)&interrupt_handler,        /* ISR 155 */
  (uint32_t)&interrupt_handler,        /* ISR 156 */
  (uint32_t)&interrupt_handler,        /* ISR 157 */
  (uint32_t)&interrupt_handler,        /* ISR 158 */
  (uint32_t)&interrupt_handler,        /* ISR 159 */
  (uint32_t)&interrupt_handler,        /* ISR 160 */
  (uint32_t)&interrupt_handler,        /* ISR 161 */
  (uint32_t)&interrupt_handler,        /* ISR 162 */
  (uint32_t)&interrupt_handler,        /* ISR 163 */
  (uint32_t)&interrupt_handler,        /* ISR 164 */
  (uint32_t)&interrupt_handler,        /* ISR 165 */
  (uint32_t)&interrupt_handler,        /* ISR 166 */
  (uint32_t)&interrupt_handler,        /* ISR 167 */
  (uint32_t)&interrupt_handler,        /* ISR 168 */
  (uint32_t)&interrupt_handler,        /* ISR 169 */
  (uint32_t)&interrupt_handler,        /* ISR 170 */
  (uint32_t)&interrupt_handler,        /* ISR 171 */
  (uint32_t)&interrupt_handler,        /* ISR 172 */
  (uint32_t)&interrupt_handler,        /* ISR 173 */
  (uint32_t)&interrupt_handler,        /* ISR 174 */
  (uint32_t)&interrupt_handler,        /* ISR 175 */
  (uint32_t)&interrupt_handler,        /* ISR 176 */
  (uint32_t)&interrupt_handler,        /* ISR 177 */
  (uint32_t)&interrupt_handler,        /* ISR 178 */
  (uint32_t)&interrupt_handler,        /* ISR 179 */
  (uint32_t)&interrupt_handler,        /* ISR 180 */
  (uint32_t)&interrupt_handler,        /* ISR 181 */
  (uint32_t)&interrupt_handler,        /* ISR 182 */
  (uint32_t)&interrupt_handler,        /* ISR 183 */
  (uint32_t)&interrupt_handler,        /* ISR 184 */
  (uint32_t)&interrupt_handler,        /* ISR 185 */
  (uint32_t)&interrupt_handler,        /* ISR 186 */
  (uint32_t)&interrupt_handler,        /* ISR 187 */
  (uint32_t)&interrupt_handler,        /* ISR 188 */
  (uint32_t)&interrupt_handler,        /* ISR 189 */
  (uint32_t)&interrupt_handler,        /* ISR 190 */
  (uint32_t)&interrupt_handler,        /* ISR 191 */
  (uint32_t)&interrupt_handler,        /* ISR 192 */
  (uint32_t)&interrupt_handler,        /* ISR 193 */
  (uint32_t)&interrupt_handler,        /* ISR 194 */
  (uint32_t)&interrupt_handler,        /* ISR 195 */
  (uint32_t)&interrupt_handler,        /* ISR 196 */
  (uint32_t)&interrupt_handler,        /* ISR 197 */
  (uint32_t)&interrupt_handler,        /* ISR 198 */
  (uint32_t)&interrupt_handler,        /* ISR 199 */
  (uint32_t)&interrupt_handler,        /* ISR 200 */
  (uint32_t)&interrupt_handler,        /* ISR 201 */
  (uint32_t)&interrupt_handler,        /* ISR 202 */
  (uint32_t)&interrupt_handler,        /* ISR 203 */
  (uint32_t)&interrupt_handler,        /* ISR 204 */
  (uint32_t)&interrupt_handler,        /* ISR 205 */
  (uint32_t)&interrupt_handler,        /* ISR 206 */
  (uint32_t)&interrupt_handler,        /* ISR 207 */
  (uint32_t)&interrupt_handler,        /* ISR 208 */
  (uint32_t)&interrupt_handler,        /* ISR 209 */
  (uint32_t)&interrupt_handler,        /* ISR 210 */
  (uint32_t)&interrupt_handler,        /* ISR 211 */
  (uint32_t)&interrupt_handler,        /* ISR 212 */
  (uint32_t)&interrupt_handler,        /* ISR 213 */
  (uint32_t)&interrupt_handler,        /* ISR 214 */
  (uint32_t)&interrupt_handler,        /* ISR 215 */
  (uint32_t)&interrupt_handler,        /* ISR 216 */
  (uint32_t)&interrupt_handler,        /* ISR 217 */
  (uint32_t)&interrupt_handler,        /* ISR 218 */
  (uint32_t)&interrupt_handler,        /* ISR 219 */
  (uint32_t)&interrupt_handler,        /* ISR 220 */
  (uint32_t)&interrupt_handler,        /* ISR 221 */
  (uint32_t)&interrupt_handler,        /* ISR 222 */
  (uint32_t)&interrupt_handler,        /* ISR 223 */
  (uint32_t)&interrupt_handler,        /* ISR 224 */
  (uint32_t)&interrupt_handler,        /* ISR 225 */
  (uint32_t)&interrupt_handler,        /* ISR 226 */
  (uint32_t)&interrupt_handler,        /* ISR 227 */
  (uint32_t)&interrupt_handler,        /* ISR 228 */
  (uint32_t)&interrupt_handler,        /* ISR 229 */
  (uint32_t)&interrupt_handler,        /* ISR 230 */
  (uint32_t)&interrupt_handler,        /* ISR 231 */
  (uint32_t)&interrupt_handler,        /* ISR 232 */
  (uint32_t)&interrupt_handler,        /* ISR 233 */
  (uint32_t)&interrupt_handler,        /* ISR 234 */
  (uint32_t)&interrupt_handler,        /* ISR 235 */
  (uint32_t)&interrupt_handler,        /* ISR 236 */
  (uint32_t)&interrupt_handler,        /* ISR 237 */
  (uint32_t)&interrupt_handler,        /* ISR 238 */
  (uint32_t)&interrupt_handler,        /* ISR 239 */
  (uint32_t)&interrupt_handler,        /* ISR 240 */
  (uint32_t)&interrupt_handler,        /* ISR 241 */
  (uint32_t)&interrupt_handler,        /* ISR 242 */
  (uint32_t)&interrupt_handler,        /* ISR 243 */
  (uint32_t)&interrupt_handler,        /* ISR 244 */
  (uint32_t)&interrupt_handler,        /* ISR 245 */
  (uint32_t)&interrupt_handler,        /* ISR 246 */
  (uint32_t)&interrupt_handler,        /* ISR 247 */
  (uint32_t)&interrupt_handler,        /* ISR 248 */
  (uint32_t)&interrupt_handler,        /* ISR 249 */
  (uint32_t)&interrupt_handler,        /* ISR 250 */
  (uint32_t)&interrupt_handler,        /* ISR 251 */
  (uint32_t)&interrupt_handler,        /* ISR 252 */
  (uint32_t)&interrupt_handler,        /* ISR 253 */
  (uint32_t)&interrupt_handler,        /* ISR 254 */
  (uint32_t)&interrupt_handler         /* ISR 255 */
};

void interrupt_handler (void)
{
  vuint32_t reg;
  reg = INTC.IACKR.R;
  while (1) {
  }

  ;                                    /* Wait forever or for watchdog timeout */
}

/*

 *######################################################################

 *                           End of File

 *######################################################################

 */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

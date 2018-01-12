/***************************************************************************************************
* SF Motors Confidential – Copyright [2017], all rights reserved.
* Author: shawn.yuan@sfmotors.com
* Date: 2017-05-25
* Description: General functions that is shared in the project.
***************************************************************************************************/

#ifndef GENERALFUNCTION_H_
#define GENERALFUNCTION_H_

#define FREQ_1M_HZ      1000000U
#define FREQ_100K_HZ    100000U
#define FREQ_10K_HZ     10000U
#define FREQ_1K_HZ      1000U
#define FREQ_100_HZ     100U
#define FREQ_50_HZ      50U
#define FREQ_10_HZ      10U
#define FREQ_1_HZ       1U

#define SAMPLETIME_10K_HZ 0.0001F

#define GF_FREQ_DIVIDER(baseFreq, targetFreq)      ((uint32_t)((baseFreq)/(targetFreq)))

#define GF_MIN(val1, val2)          (((val1)<(val2))?(val1):(val2))
#define GF_MAX(val1, val2)          (((val1)>(val2))?(val1):(val2))
#define GF_SAT(val, min, max)       (GF_MAX(GF_MIN((val), (max)), (min)))

#endif /* GENERALFUNCTION_H_ */

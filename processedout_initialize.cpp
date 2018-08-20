#include "rt_nonfinite.h"
#include "processedout.h"
#include <omp.h>
#include "processedout_initialize.h"
#include "ImageTestFunction.h"
#include "processedout_data.h"
#define b_counter                      (42.0)


void processedout_initialize()
{
  int i0;
  static const double b_last_right[3] = { -0.00059585337288756862,
    0.52936962822079359, 443.11854400427279 };

  static const double b_last_left[3] = { -0.00075007334907989007,
    0.48110083515187613, 88.548510157694523 };

  static const double b_right_fit[3] = { -0.00059585337288756862,
    0.52936962822079359, 443.11854400427279 };

  static const double b_left_fit[3] = { -0.00075007334907989007,
    0.48110083515187613, 88.548510157694523 };

  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  for (i0 = 0; i0 < 3; i0++) {
    last_right[i0] = b_last_right[i0];
    last_left[i0] = b_last_left[i0];
    right_fit[i0] = b_right_fit[i0];
    left_fit[i0] = b_left_fit[i0];
  }

  counter = b_counter;
  ImageTestFunction_init();
}

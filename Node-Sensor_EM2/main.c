#include "sl_component_catalog.h"
#include "sl_system_init.h"

#include "app.h"
#include "em_emu.h"


#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#endif
#if defined(SL_CATALOG_KERNEL_PRESENT)
#include "sl_system_kernel.h"
#else
#include "sl_system_process_action.h"
#endif

int main(void)
{

   sl_system_init();
  app_init();

#if defined(SL_CATALOG_KERNEL_PRESENT)

  sl_system_kernel_start();
#else
  while (1) {

      EMU_EnterEM2(true);
      app_process_action();

#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)

    sl_power_manager_sleep();
#endif
  }
#endif
}

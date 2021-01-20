#include "mgos_hlw8012.h"

bool mgos_mgos_hlw8012_init(void) {
	if ( mgos_sys_config_get_hlw8012_enable() ) {
		return mgos_hlw8012_init();
	} else {
		return true;
	}
}

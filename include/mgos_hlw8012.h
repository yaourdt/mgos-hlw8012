#include "mgos.h"

#ifdef __cplusplus
#include "HLW8012.h"
#endif

#ifndef MOS_LIBS_ARDUINO_XOSEPEREZ_HLW8012_SRC_MGOS_YAOURDT_HLW8012_H_
#define MOS_LIBS_ARDUINO_XOSEPEREZ_HLW8012_SRC_MGOS_YAOURDT_HLW8012_H_

#ifdef __cplusplus
extern "C"
{
#endif

bool mgos_hlw8012_init(void);

void mgos_hlw8012_begin(unsigned char cf_pin, unsigned char cf1_pin, unsigned char sel_pin,
			unsigned char currentWhen, bool use_interrupts,	unsigned long pulse_timeout);


#ifdef __cplusplus
void mgos_hlw8012_setMode(hlw8012_mode_t mode);

hlw8012_mode_t mgos_hlw8012_getMode();

hlw8012_mode_t mgos_hlw8012_toggleMode();
#endif

double mgos_hlw8012_getCurrent(void);

unsigned int mgos_hlw8012_getVoltage(void);

unsigned int mgos_hlw8012_getActivePower(void);

unsigned int mgos_hlw8012_getApparentPower(void);

unsigned int mgos_hlw8012_getReactivePower(void);

double mgos_hlw8012_getPowerFactor(void);

unsigned long mgos_hlw8012_getEnergy(void);

void mgos_hlw8012_resetEnergy(void);

void mgos_hlw8012_expectedCurrent(double current);

void mgos_hlw8012_expectedVoltage(unsigned int voltage);

void mgos_hlw8012_expectedActivePower(unsigned int power);

void mgos_hlw8012_resetMultipliers();

void mgos_hlw8012_setResistors(double current, double voltage_upstream, double voltage_downstream);

double mgos_hlw8012_getCurrentMultiplier();

double mgos_hlw8012_getVoltageMultiplier();

double mgos_hlw8012_getPowerMultiplier();

void mgos_hlw8012_setCurrentMultiplier(double current_multiplier);

void mgos_hlw8012_setVoltageMultiplier(double voltage_multiplier);

void mgos_hlw8012_setPowerMultiplier(double power_multiplier);

#ifdef __cplusplus
}
#endif

#endif /* MOS_LIBS_ARDUINO_XOSEPEREZ_HLW8012_SRC_MGOS_YAOURDT_HLW8012_H_ */

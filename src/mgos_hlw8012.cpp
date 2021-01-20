#include "HLW8012.h"
#include "mgos_hlw8012.h"

HLW8012 *sensor;

void handleCfInterrupt(int pin, void *ud) {
	if (ud == NULL) return;
	struct HLW8012 *sensor = (struct HLW8012 *) ud;
	sensor->cf_interrupt();
	(void) pin;
}

void handleCf1Interrupt(int pin, void *ud) {
	if (ud == NULL) return;
	struct HLW8012 *sensor = (struct HLW8012 *) ud;
	sensor->cf1_interrupt();
	(void) pin;
}

bool mgos_hlw8012_init() {
	if ( mgos_sys_config_get_hlw8012_cf_pin()  == -1 ) { return false; }
	if ( mgos_sys_config_get_hlw8012_cf1_pin() == -1 ) { return false; }
	if ( mgos_sys_config_get_hlw8012_sel_pin() == -1 ) { return false; }

	mgos_hlw8012_begin(
		mgos_sys_config_get_hlw8012_cf_pin(),
		mgos_sys_config_get_hlw8012_cf1_pin(),
		mgos_sys_config_get_hlw8012_sel_pin(),
		mgos_sys_config_get_hlw8012_currentWhen(),
		mgos_sys_config_get_hlw8012_interrupt(),
		mgos_sys_config_get_hlw8012_pulse_timeout()
	);
	if (sensor == NULL) return false;

	if (mgos_sys_config_get_hlw8012_current_multiplier() != 0.0) {
		mgos_hlw8012_setCurrentMultiplier(mgos_sys_config_get_hlw8012_current_multiplier());
	}

	if (mgos_sys_config_get_hlw8012_voltage_multiplier() != 0.0) {
		mgos_hlw8012_setVoltageMultiplier(mgos_sys_config_get_hlw8012_voltage_multiplier());
	}

	if (mgos_sys_config_get_hlw8012_power_multiplier() != 0.0) {
		mgos_hlw8012_setPowerMultiplier(mgos_sys_config_get_hlw8012_power_multiplier());
	}
	return true;
}


void mgos_hlw8012_begin(unsigned char cf_pin, unsigned char cf1_pin, unsigned char sel_pin,
			unsigned char currentWhen, bool use_interrupts,	unsigned long pulse_timeout) {

	sensor = new HLW8012();
	if (sensor == NULL) return;

	sensor->begin(cf_pin, cf1_pin, sel_pin, currentWhen, use_interrupts, pulse_timeout);

	if (use_interrupts) {
		mgos_gpio_set_int_handler(cf_pin, MGOS_GPIO_INT_EDGE_ANY, handleCfInterrupt, sensor);
		mgos_gpio_enable_int(cf_pin);

		mgos_gpio_set_int_handler(cf1_pin, MGOS_GPIO_INT_EDGE_ANY, handleCf1Interrupt, sensor);
		mgos_gpio_enable_int(cf1_pin);
	}
}

void mgos_hlw8012_setMode(hlw8012_mode_t mode) {
	sensor->setMode(mode);
}

hlw8012_mode_t mgos_hlw8012_getMode() {
	return sensor->getMode();
}

hlw8012_mode_t mgos_hlw8012_toggleMode() {
	return sensor->toggleMode();
}

double mgos_hlw8012_getCurrent() {
	return sensor->getCurrent();
}

unsigned int mgos_hlw8012_getVoltage() {
	return sensor->getVoltage();
}

unsigned int mgos_hlw8012_getActivePower() {
	return sensor->getActivePower();
}

unsigned int mgos_hlw8012_getApparentPower() {
	return sensor->getApparentPower();
}

unsigned int mgos_hlw8012_getReactivePower() {
	return sensor->getReactivePower();
}

double mgos_hlw8012_getPowerFactor() {
	return sensor->getPowerFactor();
}

unsigned long mgos_hlw8012_getEnergy() {
	return sensor->getEnergy();
}

void mgos_hlw8012_resetEnergy() {
	sensor->resetEnergy();
}

void mgos_hlw8012_expectedCurrent(double value) {
	sensor->expectedCurrent(value);
	mgos_sys_config_set_hlw8012_current_multiplier(mgos_hlw8012_getCurrentMultiplier());
}

void mgos_hlw8012_expectedVoltage(unsigned int value) {
	sensor->expectedVoltage(value);
	mgos_sys_config_set_hlw8012_voltage_multiplier(mgos_hlw8012_getVoltageMultiplier());
}

void mgos_hlw8012_expectedActivePower(unsigned int value) {
	sensor->expectedActivePower(value);
	mgos_sys_config_set_hlw8012_power_multiplier(mgos_hlw8012_getPowerMultiplier());
}

void mgos_hlw8012_resetMultipliers() {
	sensor->resetMultipliers();
}

void mgos_hlw8012_setResistors(double current, double voltage_upstream, double voltage_downstream) {
	sensor->setResistors(current, voltage_upstream, voltage_downstream);
}

double mgos_hlw8012_getCurrentMultiplier() {
	return sensor->getCurrentMultiplier();
}

double mgos_hlw8012_getVoltageMultiplier() {
	return sensor->getVoltageMultiplier();
}

double mgos_hlw8012_getPowerMultiplier() {
	return sensor->getPowerMultiplier();
}

void mgos_hlw8012_setCurrentMultiplier(double value) {
	sensor->setCurrentMultiplier(value);
	mgos_sys_config_set_hlw8012_current_multiplier(value);
}

void mgos_hlw8012_setVoltageMultiplier(double value) {
	sensor->setVoltageMultiplier(value);
	mgos_sys_config_set_hlw8012_voltage_multiplier(value);
}

void mgos_hlw8012_setPowerMultiplier(double value) {
	sensor->setPowerMultiplier(value);
	mgos_sys_config_set_hlw8012_power_multiplier(value);
}

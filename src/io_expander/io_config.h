/* Init Bus structure with individual devices, set all outputs LOW */
void IO_InitAll(void);

/* ===== Output channel limitation =====
 * Currently only 28 of 32 outputs are physically available.
 * Mask disables unused bits.
 * Remove this mask in future hardware revision.
 */
#define VALVE_OUTPUT_MASK 0x0FFFFFFFu /* bits 0–27 allowed, 28–31 ignored */
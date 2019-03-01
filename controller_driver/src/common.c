#include <common.h>
#include <string.h>

/***********************/
/*** Common EXT unit ***/
/***********************/

static bool m_extDriverInitialized = false;

/**
 * @brief   Initialize EXT driver with empty config
 * @note    Safe to call any times, it checks state of previous call
 * @note    Must be called before EXT driver work
 */
void commonExtDriverInit ( void )
{
    if ( m_extDriverInitialized )
        return;

    EXTConfig extcfg;
    for ( expchannel_t ch = 0; ch < EXT_MAX_CHANNELS; ch++ )
    {
        extcfg.channels[ch].mode  = EXT_CH_MODE_DISABLED;
        extcfg.channels[ch].cb    = NULL;
    }
    extStart( &EXTD1, &extcfg );

    m_extDriverInitialized = true;
}












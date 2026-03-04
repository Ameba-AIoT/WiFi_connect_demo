#ifndef _WIFI_CONNECT_DEMO_H_
#define _WIFI_CONNECT_DEMO_H_

#include <platform_autoconf.h>
#include "os_wrapper.h"
#include "platform_stdlib.h"
#include "basic_types.h"
#include "wifi_api.h"
#include "lwip_netconf.h"


#define TAG         "WIFI_RECONN_DEMO" 
#define RETRY_LIMIT			3
#define RETRY_INTERVAL		5000    // ms
#define SSID                "ax3"   //2.4G WiFi channel
#define PASSWORD            "12345678"

#define LED1_PIN _PA_14 //G
#define LED2_PIN _PA_15 //R

void gpio_led_init(void);
void gpio_toggle(u32 GPIO_Pin, int time_ms);
void WiFi_connect_demo_task(void *param);
int user_WiFi_connect(void);

#endif

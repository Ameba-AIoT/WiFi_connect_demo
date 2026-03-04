* [中文版](./README_CN.md)

### RTL8721Dx Manual WiFi AP Connection Demo (FreeRTOS)

🔹 This example demonstrates how to use the RTL8721Dx series SoC WiFi API to connect to an AP.

- 📎 EVB Purchase Links: [🛒 Taobao](https://item.taobao.com/item.htm?id=904981157046) | [📦 Amazon](https://www.amazon.com/-/zh/dp/B0FB33DT2C/)
- 📄 [Chip Information](https://aiot.realmcu.com/cn/module/index.html)
- 📚 [WiFi API Documentation](https://aiot.realmcu.com/cn/latest/rtos/wifi/api/index.html)

---

### Features

✅ Disable the built-in WiFi reconnect mechanism in the SDK first  
✅ `WiFi_connect_demo.h` defines the SSID (`ax3`) and password (`12345678`), which can be modified as needed  
✅ During retry connection, the LED blinks in red  
✅ After WiFi is connected successfully, the LED turns green  
✅ Use AT commands to check WiFi status information  

### Hardware Setup

1️⃣ **Required Components**
   - AP with 802.11bgn mode enabled  
   - RTL8721Dx EVB (with WiFi antenna)

2️⃣ **WiFi Configuration**
   - Configure the AP SSID and password:
   ```c
   #define SSID                "ax3"   // abgn mode
   #define PASSWORD            "12345678"
   ```

3️⃣ **Disable SDK WiFi Auto-Reconnect**
   - Modify the following configuration:
   ```c
   // {sdk}/component/soc/usrcfg/amebadplus/ameba_wificfg.c
   wifi_user_config.fast_reconnect_en = 0;
   wifi_user_config.auto_reconnect_en = 0;
   ```

### Quick Start

1️⃣ **Initialize SDK Environment**
   - Set the `env.sh` (`env.bat`) path:
     ```bash
     source {sdk}/env.sh
     ```
   - Replace `{sdk}` with the absolute path to the root directory of the [ameba-rtos SDK](https://github.com/Ameba-AIoT/ameba-rtos).

⚡ **Note**: This example supports SDK version **≥ v1.2**.

2️⃣ **Build**
   ```bash
   source env.sh
   ameba.py build -p
   ```

3️⃣ **Flash Programming**
   ```bash
   ameba.py flash --p COMx --image km4_boot_all.bin 0x08000000 0x8014000 --image km0_km4_app.bin 0x08014000 0x8200000
   ```
   ⚠️ Note: Precompiled bin files are also provided in the project directory and can be flashed as follows:
   ```bash
   ameba.py flash --p COMx --image ../km4_boot_all.bin 0x08000000 0x8014000 --image ../km0_km4_app.bin 0x08014000 0x8200000
   ```

4️⃣ **Open Serial Monitor**
   ```bash
   ameba.py monitor --port COMx --b 1500000
   ```

5️⃣ **Press the EVB RST Button and Observe WiFi Connection**
   - Use the following AT command to check WiFi status:
     ```text
     AT+WLSTATE
     ```

---

### 📝 Log Example

```bash
Logs:
11:01:31.111  ROM:[V1.1]
11:01:31.111  FLASH RATE:1, Pinmux:1
11:01:31.111  IMG1(OTA1) VALID, ret: 0
11:01:31.111  IMG1 ENTRY[f800779:0]
11:01:31.111  [BOOT-I] KM4 BOOT REASON 0: Initial Power on
11:01:31.111  [BOOT-I] KM4 CPU CLK: 240000000 Hz
11:01:31.111  [BOOT-I] KM0 CPU CLK: 96000000 Hz
11:01:31.111  [BOOT-I] PSRAM Ctrl CLK: 240000000 Hz 
11:01:31.111  [BOOT-I] IMG1 ENTER MSP:[30009FDC]
11:01:31.111  [BOOT-I] Build Time: Mar  2 2026 10:46:49
11:01:31.111  [BOOT-I] IMG1 SECURE STATE: 1
11:01:31.111  [FLASH-I] FLASH CLK: 80000000 Hz
11:01:31.111  [FLASH-I] Flash ID: 85-20-16 (Capacity: 32M-bit)
11:01:31.111  [FLASH-I] Flash Read 4IO
11:01:31.111  [FLASH-I] FLASH HandShake[0x2 OK]
11:01:31.111  [BOOT-I] KM0 XIP IMG[0c000000:55960]
11:01:31.127  [BOOT-I] KM0 SRAM[20068000:3120]
11:01:31.127  [BOOT-I] KM0 PSRAM[0c058a80:20]
11:01:31.127  [BOOT-I] KM0 ENTRY[20004d00:60]
11:01:31.127  [BOOT-I] KM4 XIP IMG[0e000000:69c60]
11:01:31.127  [BOOT-I] KM4 SRAM[2000b000:1ee0]
11:01:31.127  [BOOT-I] KM4 PSRAM[0e06bb40:20]
11:01:31.127  [BOOT-I] KM4 ENTRY[20004d80:40]
11:01:31.127  [BOOT-I] IMG2 BOOT from OTA 1, Version: 1.1 
11:01:31.127  [BOOT-I] Image2Entry @ 0xe00d79d ...
11:01:31.127  [APP-I] KM4 APP START 
11:01:31.127  [APP-I] VTOR: 30007000, VTOR_NS:30007000
11:01:31.127  it_retarget_lock[APP-I] s
11:01:31.127  [APP-I] IMG2 SECURE STATE: 1
11:01:31.127  [CLK-I] [CAL131K]: delta:9 target:2441 PPM: 3687 PPM_Limit:30000 
11:01:31.143  [LOCKS-I] KM4 init_retarget_locks
11:01:31.143  [APP-I] BOR arises when supply voltage decreases under 2.57V and recovers above 2.7V.
11:01:31.143  [MAIN-I] KM4 MAIN 
11:01:31.143  [VER-I] AMEBA-RTOS SDK VERSION: 1.2.0
11:01:31.143  [MAIN-I] File System Init Success 
11:01:31.143  [WIFI_RECONN_DEMO-I] Customize wifi connect demo start!
11:01:31.143  [MAIN-I] KM4 START SCHEDULER 
11:01:31.143  interface 0 is initialized
11:01:31.143  interface 1 is initialized
11:01:31.143  [WLAN-I] LWIP consume heap 1312
11:01:31.143  [WIFI_RECONN_DEMO-I] start
11:01:31.143  [WLAN-A] Init WIFI
11:01:31.159  [WLAN-A] Band=2.4G&5G
11:01:31.190  [WLAN-I] NP consume heap 20400
11:01:31.190  [WLAN-I] AP consume heap 10400
11:01:31.190  [WLAN-I] Available heap after wifi init 332224
11:01:31.190  [WIFI_RECONN_DEMO-I] Wifi connect start, retry cnt = 0
11:01:31.190  [WLAN-A] set ssid ax3
11:01:36.495  [WLAN-A] start auth to e2:b8:37:8c:65:9c
11:01:36.527  [WLAN-A] auth success, start assoc
11:01:36.558  [WLAN-A] assoc success(1)
11:01:36.621  [WLAN-A] set pairwise key 4(WEP40-1 WEP104-5 TKIP-2 AES-4 GCMP-15)
11:01:36.636  [WLAN-A] set group key 4 1
11:01:36.636  [WLAN-I] set cam: gtk alg 4 0
11:01:36.636  [$]wifi connected
11:01:36.636  [WIFI_RECONN_DEMO-I] Wifi connect success, Start DHCP
11:01:37.649  [$]wifi got ip:"192.168.4.62"
11:01:37.649  wtn dhcp success
11:01:38.151  [WIFI_RECONN_DEMO-I] DHCP Success
11:01:42.148  AT+WLSTATE
11:01:42.148  [+WLSTATE]: _AT_WLAN_INFO_
11:01:42.148  WLAN0 Status: Running
11:01:42.148  ==============================
11:01:42.148  WLAN0 Setting:
11:01:42.148  ==============================
11:01:42.148        MODE => STATION
11:01:42.148        SSID => ax3
11:01:42.148       BSSID => e2:b8:37:8c:65:9c
11:01:42.148     CHANNEL => 6
11:01:42.148    SECURITY => WPA2 AES
11:01:42.148    PASSWORD => 12345678
11:01:42.148  
11:01:42.148  Interface (0)
11:01:42.148  ==============================
11:01:42.148  MAC => c4:e5:b1:13:81:e0
11:01:42.148  IP  => 192.168.4.62
11:01:42.148  GW  => 192.168.4.1
11:01:42.148  MSK  => 255.255.255.0
11:01:42.148  
11:01:42.148  OK
11:01:42.148  
11:01:42.148  [MEM] After do cmd, available heap 332448
11:01:42.148  
11:01:42.148  #
```
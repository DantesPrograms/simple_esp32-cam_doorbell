# simple_esp32-cam_doorbell
A simplified version of https://github.com/DantesPrograms/ESP32-CAM_smart_doorbell_pre-release

# BASIC ESP32-CAM DOORBELL
## Just Button + Buzzer - That's It! 🔔

---

## What It Does:
✅ Press button → Plays "ding dong" sound  
✅ **THAT'S ALL!**

No WiFi. No webpage. No camera stream. No complications.

---

## Wiring (2 minutes):

```
ESP32-CAM:
├─ GPIO 13 → Button → GND
├─ GPIO 14 → Buzzer (+) → Buzzer (-) → GND
├─ 5V → Power
└─ GND → Power
```

**Components:**
- 1x Button (momentary switch)
- 1x Passive buzzer (NOT active buzzer!)
- Wires

**That's it. No LEDs. No SD card. Nothing else.**

---

## Upload:

1. Connect FTDI to ESP32-CAM
2. Connect **GPIO 0 to GND** (for programming mode)
3. Upload `basic_doorbell.ino`
4. **DISCONNECT GPIO 0 from GND**
5. Press RESET

---

## Test:

Press the button → Hear "ding dong"

**Done!** 🎉

---

## Serial Monitor Output:

```
================================
ESP32-CAM DOORBELL
================================

✓ Pins configured
✓ Button ready
✓ Camera ready

================================
🔔 DOORBELL READY!
================================
Press the button to ring!
================================
```

---

## Notes:

- Camera initializes but **isn't used for anything**
- No WiFi needed
- No web server
- Works completely offline
- Just a simple doorbell sound when button pressed

**Perfect for when you just want a doorbell that goes "ding dong"!** 🔔

# IoT
# IoT Fire Detection System
An IoT-based fire and intrusion detection system using ESP8266 and Blynk platform.

## Features
- Real-time fire detection using flame sensor
- Smoke/Gas level monitoring
- Mobile notifications via Blynk app
- Email alerts for emergency situations
- LED and buzzer indicators for local warnings
- Relay control for automated response

## Hardware Requirements
- NodeMCU ESP8266
- Flame Sensor (Connected to D6)
- Smoke/Gas Sensor (Connected to A0)
- LED (Connected to D7)
- Buzzer (Connected to D2)
- Relay Module (Connected to D1)

## Software Requirements
- Arduino IDE
- Blynk IoT Platform
- Required Libraries:
  - ESP8266WiFi
  - BlynkSimpleEsp8266

## Setup Instructions
1. Install Arduino IDE and required libraries
2. Create a Blynk account and new project
3. Configure WiFi credentials in the code
4. Upload the code to NodeMCU
5. Connect the hardware components according to the pin configuration

## Pin Configuration
```
NodeMCU ESP8266 Connections:
- D7 (GPIO13) -> LED
- D6 (GPIO12) -> Flame Sensor
- D2 (GPIO4)  -> Buzzer
- D1 (GPIO5)  -> Relay
- A0         -> Smoke/Gas Sensor
```

## Circuit Diagram
![image](https://github.com/user-attachments/assets/e445a63f-de74-4f5d-9407-fbe288e44a16)


## Usage
1. Power on the system
2. Connect to specified WiFi network
3. Monitor through Blynk mobile app
4. System will automatically:
   - Detect flame and smoke presence
   - Trigger local alarms (LED, buzzer)
   - Send mobile notifications
   - Send email alerts
   - Activate relay for connected devices

## Contributing
Feel free to contribute to this project by:
1. Forking the repository
2. Creating your feature branch
3. Committing your changes
4. Pushing to the branch
5. Creating a new Pull Request

## License
This project is licensed under the MIT License - see the LICENSE file for details.

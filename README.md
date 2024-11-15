# Sensor Data Logger Project

This repository contains a project for logging sensor data using a microcontroller. The project includes reading data from various sensors, processing it, and saving it for later analysis. This project is ideal for those interested in embedded systems, data logging, and sensor networks.

## Features

- **Sensor Data Acquisition**: Collect data from different types of sensors, such as temperature, humidity, or light sensors.
- **Data Logging**: Store the sensor data in memory for later retrieval and analysis.
- **Configurable Sampling Rate**: Adjust the rate at which sensor data is collected.
- **User-Friendly Interface**: Simple setup and clear code structure to facilitate easy modifications.

## Requirements

- **Hardware**: Microcontroller (e.g., ESP32, STM32, or Arduino) and compatible sensors
- **Software**:
  - Arduino IDE or PlatformIO (for ESP32/Arduino)
  - Required sensor libraries for your hardware

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/aalexanderfc/uppgift_1_inbyggdaSystem.git
   cd uppgift_1_inbyggdaSystem
   ```

2. **Open the Project**:
   - For Arduino IDE, open the `.ino` file in the Arduino IDE.
   - For PlatformIO, open the project folder in VS Code.

3. **Connect Your Hardware**:
   - Connect your sensors to the microcontroller according to the pin configurations specified in the code.

4. **Configure Pins (Optional)**:
   - Modify the pin assignments in the code to match your specific hardware configuration.

5. **Upload the Code**:
   - Connect your microcontroller to your computer via USB.
   - Compile and upload the code to your board.

## Usage

- **Data Collection**: The project reads sensor values at a defined interval and stores them in memory.
- **Retrieving Data**: Data can be retrieved and analyzed after logging, providing insights into environmental conditions or system performance.
- **Customization**: Users can add different sensors or change the sampling rate as needed.

## How It Works

This project reads sensor values periodically using a microcontroller, and logs the data for future analysis:

- **Sensors**: Various types of sensors can be connected and their data collected.
- **Data Logging**: The collected sensor data is stored locally on the microcontroller, and can be accessed or transmitted for analysis.

## Example Code

Here is a brief example of what the code looks like:

```cpp
void setup() {
    // Setup code for initializing sensors and data logging
}

void loop() {
    // Main loop code for reading sensor data and logging it
}
```

For detailed code, please refer to the specific `.ino` file in the repository.

## Limitations

- The amount of data that can be logged is limited by the memory of the microcontroller.
- Custom modifications might be required for different types of sensors.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Author

Developed by Alexander. Feel free to reach out for more information or collaboration opportunities.


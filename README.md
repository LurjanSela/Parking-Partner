# Parking Partner

**Team:**
- Lurjan Sela, COE
- Jude Clidoro, COE
- Julia Wojcik, COE

**Faculty Advisor: Dr. Sosnowski**

## Project Objectives
- Utilize a microcontroller and attachable sensors to assist drivers with parking.
- Use an Arduino to store the data gathered from the sensors.
- Deliver instructions to the linked LED strips so that the driver can be guided.
- Alert the driver that something is in the proximity of the sensors.
- Promote the system to customers who lack experience with parking or access to smart features.

## Potential Applications and Societal Benefits
- Aid for inexperienced drivers.
- Drivers with a fear of parking.
- Drivers without cars that have parking assist features.
- Preventing drivers from damaging other cars or their own car.

## Approach
- Implemented an ELEGOO 2560 Mega Board to interact with HC-SR04 sensors, LED strips, and a buzzer.
- Attached ultrasonic sensors at the corner bumpers of the car.
- Created a software program in Arduino IDE.
  - Takes data from sensors to interact with the LED strips.
  - LED strips light up either RED, GREEN, or YELLOW depending on the distance read.
  - When the distance reaches a certain limit, the program makes the buzzer go off to alert the driver.

## Budget
- **Components Cost**
  - HC-SR04 Ultrasonic Module Sensors (5) - $12.99
  - Mega R3 Board ATmega 2560 + USB Cable - $20.99
  - BTF-Lighting WS2812B RGB (2 strips of 6.5in) - $2.50
  - ELEGOO Dupont Wires - $6.98
  - Adafruit Buzzer 5V - $6.99
  - 3-D Printed Housings - $15.00
  - **Total - $65.45**

## Learning Experience
- Learned how to utilize hardware and software components together to create a real-world application.
- Understood and worked around design limitations.
  - How far the sensors can detect?
  - What is the most efficient way to have sensors interacting with all electrical components?
- Explored alternative approaches.
  - Apply a Raspberry Pi controller.
  - Include a Bluetooth module.
  - Phone application.
  - Include more diverse set of sensors.
    - Proximity sensors.
    - Camera sensors.

## Future Potential: Development
- **Hardware:**
  - Add more Sensors: increase coverage area or add redundancy in case a sensor fails.
  - Multi-Threaded Microcontroller: Use a microcontroller with multiple cores and a lower frequency.
  - Separate Battery.

- **Machine Learning:**
  - Classify objects based on their shape and size.
    - Cars vs Pedestrians vs Curbs.

- **Camera:**
  - To recognize objects in real time.

- **Feedback Mechanism:**
  - Voice prompts or an LCD screen to alert the driver.

## Future Potential: Market
- **Home application:**
  - Integrate with smart homes.
    - Alerts when someone is approaching their home.
    - Alerts when someone is approaching their vehicle.

- **Driving Schools:**
  - The device can be used by driving instructors to aid in teaching students how to drive and park.

- **Commercial:**
  - The device can be used by commercial trucks to help avoid collisions at loading docks.

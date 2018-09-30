# Traffic-Management-System

In today’s world, one of the major problems commuters face every day is mismanaged traffic signals. With the increase in the standard of living, the vehicular density has also increased. Increased vehicular density of road is accompanied by a number of problems. Breaking traffic rules which lead to road accidents are a few of them. Here is a scope for trying to reduce a few of them. For example, in the current system, even if there are no vehicles on one side of the road, that signal is scheduled uniformly as others. This causes frustration to the driver, leading to serious problems such as road rage and causes people to ”jump” signals. Here, we have a solution to the problem by dynamically scheduling the traffic signal lights for each lane based on the vehicular density on that particular the lane.
 
## Introduction
Traffic Monitoring and Management is one of the most difficult challenges being faced by metro cities these days. Due to the exponential rise in the vehicle population on the road, many serious problems such as pollution and road accidents are one the rise. Millions of people lose their lives to heinous road accidents every year.  Hundreds of millions of dollars are put into research to try and reduce such incidents. Hence an honest effort has to be put in this regard. We here in this project have implemented a naïve method to dynamically schedule the traffic signals so as to dissolve the traffic jams and allow easy movement of vehicles on the road.

## Components used
1. Arduino UNO microcontroller
2. IR sensors
3. RFID reader module
4. RFID tags

## Methodology

We here in this project have used an Arduino UNO Microcontroller to which have been attached IR sensors and the RFID reader module. The IR Sensors detect any vehicle in proximity. The IR emitter emits out IR radiations into the ambience which is then picked up by the IR receiver. Based on the intensity of the radiation sensed by the receiver, the proximity of the object is updated to the Arduino by the sensor. The RF reader module is also attached to the Arduino. This sensor detects any RF ID tag in its proximity and updates the Arduino with the RFID tag number. Here, we have used a passive RFID tag. The RF ID Tag comes along with a coil and a chip inside it. When this ID comes in good proximity to the reader, electricity is induced in the coil by the method of electromagnetic induction which powers up the chip. The ID is then sent electromagnetically to the receiver by the chip.

## Implementation
The IR Proximity Sensors are placed at regular intervals of 8cm on the sides of the lanes in our model. We are considering a three lane junction and hence using 6 sensors (2 for each lane). For demo purpose, we have RF ID reader only for one lane. RGB LED’s are used as signals

The number of sensors active at a given instant of time, the length of the traffic at that particular lane is determined. Based on this idea the traffic signal at that lane is prioritized. If the first sensor has been activated, the signal remains green for 30s. If both have been activated, the signal length is about 60s. If neither of them is activated, indicating the there is very less traffic on that lane, the delay is 15s.

In addition to the dynamic traffic signal scheduling, the system also detects an ambulance’s approach by reading the RF ID mounted on it. The RFID reader module is placed on every road which, when detects an ambulance prioritizes that road’s signal first. After the ambulance passes the signal, the system retorts to the conventional scheduling.

## Drawbacks
1. The IR Sensors used in this project may be vulnerable to stray light. Hence, as an improvement over this drawback we might use ultrasonic sensors for proximity detection. 
2. The priority for ambulance and other VIP vehicles may be decided based on the RFID tag number.

## REFERENCES
1. http://electronics.stackexchange.com
2. http://forum.arduino.cc
3. http://arduino.stackexchange.com
4. https://learn.adafruit.com
5. https://electrosome.com

# Sea-Weather-and-Pollution-Transmitter-Buoy
This project is under the Course No ECE-3108 and Title : Digital Communication Sessional  
Date: 06-04-2023

The project is Supervised by  
Dr. Md. Shamim Ahsan,  
Professor,   
Electronics and Communication Engineering Discipline,   
Khulna University,  Khulna, Bangladesh.

Project by,
Sheyum Hossain,  
Electronics and Communication Engineering Discipline,  
Khulan University, Khulna   

Hasibul Hassan,
Electronics and Communication Engineering Discipline,  
Khulan University, Khulna  

# Objectives:
1.	Measuring of sea water quality.
2.	Measuring of sea water Temperature.
3.	Measuring of sea weather air quality (Humidity, Pressure, Temperature).
4.	Detection of Spate.
5.	Solar based system.
   
# Introduction:
Unlike weather on land, sea weather is highly unpredictable and changes drastically at times. Keeping track of sea weather at all times is a very tough task. Also, sea pollution is a growing issue of concern and the first step to controlling pollution is measuring it. Another problem is the unavailability of cellular or other data networks in sea or data transmission. It is necessary to use small sea weather stations with own data transmission capability in the sea at all times to get data about these details. So, we hereby design and want develop a small sea weather as well as sea pollution monitoring station that can transmit this data over to the monitoring station on sea shores.  
# Component  
·	Solar Panel
·	GY-BME280 Temperature and Humidity Sensor
·	6DOF MPU 6050 3 Axis Gyro
·	LM 35 sensor
·	NRF24L01+PA+LNA 2.4GHz SMA Antenna Wireless Transceiver communication module
·	Liquid Suspended Particles Turbidity Sensor Detection Module Kit.
·	Esp 32
·	Wire
·	Power supply  

# Procedure:   
According to the circuit diagram all the modules was integrated together with the microcontroller both on the Transmitting and Receiving side. In transmitted side that circuit is implemented on a . After implementing the circuit.  
On the Receiver Blynk app was used to visualize the data received from the Buoy.  
# Block Diagram
![image](https://github.com/user-attachments/assets/259a0df0-6ab9-4f45-99e8-d15359de6300)  
# Outcome:  
Sea weather and water information was transmitted using Radio Frequency.  

![Demo](https://github.com/user-attachments/assets/f501424e-fe4b-44a6-8415-a0c55a509239)  

![image](https://github.com/user-attachments/assets/cd8ab573-a1a6-4fd0-8e86-21cb86a51424)  
Figure: Visualizing the Weather information of the sea in Web Interface.  

![image](https://github.com/user-attachments/assets/cb094c8e-06a9-4c85-bc34-e1a909c2791d) ![image](https://github.com/user-attachments/assets/ed3c1ebb-cdcc-421e-ade7-86dcc621c2bc)  
Figure : Transmitter Boyu.  

![image](https://github.com/user-attachments/assets/4def3645-2e1e-44bc-bc15-1db7c1230b4d)  
Figure : Receiver.  

# Conclusion : The use of Arduino and the nrf24L01 module allows for wireless transmission of data over long distances, making it an ideal solution for applications such as remote monitoring of ocean parameters.
This project demonstrates the ability to collect and transmit various environmental parameters using an Arduino board and nrf24L01 module. The TDS sensor measures the amount of total dissolved solids in water, which can be indicative of water quality. The sea temperature sensor provides data on the temperature of the water, which is important for oceanographers and marine biologists. The water quality sensor measures the quality of the water, which are important parameters for monitoring the health of marine ecosystems. Lastly, the sea air pressure sensor provides information on atmospheric pressure, which can affect ocean currents and weather patterns.
Overall, the project showcases the versatility and functionality of Arduino and the nrf24L01 module, providing a platform for scientists and researchers to collect and analyze environmental data in real-time. With further development, this project can potentially be used in various applications, such as oceanography, marine biology, and environmental monitoring.









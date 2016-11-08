Install Robot Operating System (ROS)
https://xv11hacking.wikispaces.com/Connecting+to+ROS

From source:
https://xv11hacking.wikispaces.com/XV-11+API+Commands

Basic move command:

setmotor leftwheeldistance rightwheeldistance speed

More information on movement specs:
http://xv11hacking.wikispaces.com/Motors

There is also a neato C# API:
https://github.com/squid-box/NeatoCSharpAPI

To move neato in a rectangle:

1. enable test mode:
  testmode on

2. Drive forward 10cm:
  setmotor 100 100 100

3. Rotate clockwise 90 degrees:
  setmotor 195 -195 100

4. Drive forward 20 cm:
  setmotor 200 200 100

5. Rotate clockwise 90 degrees:
  setmotor 195 -195 100

6. Drive forward 10 cm:
  setmotor 100 100 100

7. Rotate clockwise 90 degrees:
  setmotor 195 -195 100

8. Drive forward 20 cm:
  setmotor 200 200 100

9. Do a victory dance (spin on the spot 360 degrees, maybe?):
  setmotor 900 -900 100
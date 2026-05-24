# Arduino & C Projects – Priscila Carolina Padilla Collaguazo

A collection of embedded systems and software projects developed during my
studies in Electrical Engineering for Sustainable Energy Systems at FH Aachen,
and prior studies in Electronics and Automation Engineering.

---

## Projects Overview

| # | Project | Language | Hardware |
|---|---------|----------|----------|
| 1 | DHT11 Temperature & Humidity Sensor | C++ (Arduino) | Arduino, DHT11 sensor |
| 2 | LCD Display Showcase | C++ (Arduino) | Arduino, 16x2 LCD |
| 3 | Transit Card App | C | Console (PC) |
| 4 | Conveyor Belt Object Counter | C++ (Arduino) | Arduino, LCD, LDR, DC motor |

---

## 1. DHT11 Temperature & Humidity Sensor

Reads temperature (°C) and relative humidity (%) from a DHT11 sensor and
prints the values to the Serial Monitor every second.

### Hardware
- Arduino Uno (or compatible)
- DHT11 sensor

### Wiring
| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| VCC       | 5V          |
| GND       | GND         |
| DATA      | A0          |

### Dependencies
Install the **DHT sensor library** by Adafruit via the Arduino Library Manager:
`Sketch → Include Library → Manage Libraries → search "DHT sensor library"`

### Example Output
```
RH(%):55.00 Temp:23.00 *C
```

---

## 2. LCD Display Showcase

An animated 16x2 LCD sequence that scrolls through university info, a full
name typed out letter by letter, a blinking date screen, and a time display
with custom pixel art characters in the corners.

### Hardware
- Arduino Uno (or compatible)
- 16x2 LCD display (HD44780 compatible)
- 10kΩ potentiometer (for contrast)

### Wiring
| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | 13          |
| E       | 12          |
| D4      | 11          |
| D5      | 10          |
| D6      | 9           |
| D7      | 8           |

### Dependencies
Uses the built-in **LiquidCrystal** library — no installation needed.

### Display Sequence
1. University name with custom `!` character
2. Faculty name — scrolls left
3. Degree program — scrolls left with accented characters
4. Full name typed out letter by letter (typewriter effect)
5. Date with smiley face decoration — blinks twice
6. Time with alien and star pixel art in each corner

### Custom Characters
| Name        | Description           |
|-------------|-----------------------|
| exclamation | Bold `!` mark         |
| letterI     | Accented `í`          |
| letterO     | Accented `ó`          |
| smileyFace  | Simple smile icon     |
| alien       | Small alien face      |
| star        | 4-pointed star        |

### Notes
- Date and time are hardcoded. To make them dynamic, integrate an RTC module
  (e.g. DS1307 or DS3231).

---

## 3. Transit Card App

A console-based prototype of a transit payment app written in C. Users can
register their personal info, calculate trip costs by destination and transport
type, and manage their card balance with top-ups.

### How to Compile & Run
```bash
gcc transit_card.c -o transit_card -lm
./transit_card
```
> The `-lm` flag links the math library (`math.h`).

### Menu Options
| Option | Description                   |
|--------|-------------------------------|
| 1      | Enter or update personal info |
| 2      | Calculate cost of a trip      |
| 3      | Top up account balance        |
| 4      | Exit the program              |

### Available Destinations
**Bus:** Quito, Cumbaya, Valle, Sur, Norte  
**Train:** Quito, Tambillo, Machachi, Boliche

### Known Limitations / TODOs
- Destination-to-cost mapping (each stop needs a fixed price assigned)
- Age-based discounts (children, students, elderly)
- Automatic balance deduction after each trip
- Case-insensitive destination input (e.g. "quito" = "Quito")

### Notes
- Written as a university final project prototype
- Nested functions are used (GCC extension, not standard C)
- Balance starts at 0 and persists only during the current session

---

## 4. Conveyor Belt Object Counter

Uses a photoresistor (LDR) and laser beam to count objects passing along a
conveyor belt. A 16x2 LCD displays the running count, a blue LED signals each
detection, and a DC motor drives the belt forward, backward, or stops it based
on the count.

### Hardware
- Arduino Uno (or compatible)
- 16x2 LCD display (HD44780 compatible)
- Photoresistor (LDR) + laser pointer or IR emitter
- DC motor + motor driver (e.g. L298N)
- Blue LED + 220Ω resistor
- 10kΩ potentiometer (for LCD contrast)

### Wiring

**LCD**
| LCD Pin | Arduino Pin |
|---------|-------------|
| RS      | 13          |
| E       | 12          |
| D4      | 11          |
| D5      | 10          |
| D6      | 9           |
| D7      | 8           |

**Other Components**
| Component           | Arduino Pin |
|---------------------|-------------|
| Blue LED            | 3 (OUTPUT)  |
| Motor speed (PWM)   | 6 (OUTPUT)  |
| Motor direction A   | 4 (OUTPUT)  |
| Motor direction B   | 2 (OUTPUT)  |
| Photoresistor (LDR) | A0 (INPUT)  |

### How It Works
1. A laser beam points at the photoresistor across the conveyor belt.
2. When an object passes through, it blocks the beam and lowers the sensor
   reading below the threshold (300).
3. The blue LED turns on and the counter increments by 1.
4. While the object is still blocking the beam, the count is held (no double-counting).
5. Once the beam is restored, the LED turns off and the system waits for the next object.

### Belt Behaviour by Count
| Object Count | Belt Action  |
|--------------|--------------|
| Less than 6  | Move forward |
| 5 to 15      | Move backward |
| More than 15 | Stop         |

### Sensor Threshold
The detection threshold is set at **300** (out of 1023). Adjust this value
in `checkSensor()` to match your lighting conditions:
```cpp
if (sensorValue >= 300) { // increase if too sensitive, decrease if missing objects
```

### Dependencies
Uses the built-in **LiquidCrystal** library — no installation needed.

---

## About

These projects were developed as part of my electrical engineering education,
covering embedded software, hardware interfacing, sensor integration, and
foundational C/C++ programming. They form part of my practical portfolio
alongside video demonstrations of each working prototype.

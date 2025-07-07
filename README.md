# 🧠 Arduino Lie Detector (Skin Conductivity / GSR)

This is a simple Arduino-based lie detector prototype using **Galvanic Skin Response (GSR)** to measure changes in skin conductivity.

During the first 5 seconds, the system calibrates a baseline (`skinConductivity`). It then compares real-time readings to detect deviations, which are visualized through LEDs and plotted in real time.

## 🔧 Features

- Automatic 5-second calibration at startup
- LED feedback:
  - 🟢 Green LED → Conductivity below threshold (low stress)
  - 🟡 Yellow LED → Moderate increase (+10%)
  - 🔴 Red LED → High increase (+20%)
- Serial Plotter visualization with 4 signals:
  - Baseline
  - Baseline + 10% (tolerance)
  - Baseline + 20%
  - Real-time A0 reading

## 🧪 How It Works

1. Two electrodes are placed on the skin (e.g., fingers).
2. Arduino reads analog values from pin A0.
3. A baseline is computed as the average of 250 samples taken during the first 5 seconds.
4. The current reading is compared to this baseline:
   - If over +20% → Red LED ON
   - If over +10% → Yellow LED ON
   - If below +10% → Green LED ON

## 🖥️ Serial Plotter Output

Every cycle, the following values are sent (tab-separated):

1. `skinConductivity` (baseline)
2. `skinConductivity + tolerance` (10% above)
3. `skinConductivity + 2 * tolerance` (20% above)
4. `value` (real-time A0 reading)

This allows you to track the skin response over time via Arduino’s Serial Plotter.

## 🧰 Hardware Requirements

- Arduino Uno (or compatible board)
- 3 LEDs (Green, Yellow, Red) + resistors
- 3x 220Ω resistors
- 1x 1MΩ resistor
- Breadboard + jumper wires
- 1 human finger

## 📷 Preview

![image](https://github.com/user-attachments/assets/68bce1bc-b2c3-418c-b894-dc4513451c33)

## ⚠️ Disclaimer

This project is for educational and experimental purposes only. GSR is not a reliable lie detector but can demonstrate physiological changes.

## 📄 License

GNU License

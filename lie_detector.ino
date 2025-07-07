const int ledBasso = 9;
const int ledMedio = 10;
const int ledAlto = 11;

float skinConductivity = 0.0;
float tolerance = 0.0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledBasso, OUTPUT);
  pinMode(ledAlto, OUTPUT);
  pinMode(ledMedio, OUTPUT);

  // Accensione iniziale dei LED per 5 secondi
  digitalWrite(ledBasso, HIGH);
  digitalWrite(ledAlto, HIGH);
  digitalWrite(ledMedio, HIGH);

  long sum = 0;
  const int samples = 250;

  for (int i = 0; i < samples; i++)
  {
    sum += analogRead(A0);
    delay(20);
  }

  skinConductivity = sum / (float)samples;
  tolerance = skinConductivity * 0.10f;

  // Spegni i LED dopo calibrazione
  digitalWrite(ledBasso, LOW);
  digitalWrite(ledAlto, LOW);
  digitalWrite(ledMedio, LOW);
}

void loop()
{
  int value = analogRead(A0);

  // 📊 Stampa solo i 4 valori richiesti, separati da tab
  Serial.print(skinConductivity);
  Serial.print('\t');
  Serial.print(skinConductivity + tolerance);
  Serial.print('\t');
  Serial.print(skinConductivity + 2 * tolerance);
  Serial.print('\t');
  Serial.println(value);

  // Logica LED
  if (value > skinConductivity + 2 * tolerance)
  {
    digitalWrite(ledAlto, HIGH);
    digitalWrite(ledMedio, LOW);
    digitalWrite(ledBasso, LOW);
  }
  else if (value > skinConductivity + tolerance)
  {
    digitalWrite(ledMedio, HIGH);
    digitalWrite(ledAlto, LOW);
    digitalWrite(ledBasso, LOW);
  }
  else if (value < skinConductivity + tolerance)
  {
    digitalWrite(ledBasso, HIGH);
    digitalWrite(ledMedio, LOW);
    digitalWrite(ledAlto, LOW);
  }
  else
  {
    digitalWrite(ledBasso, LOW);
    digitalWrite(ledMedio, LOW);
    digitalWrite(ledAlto, LOW);
  }

  delay(20);
}

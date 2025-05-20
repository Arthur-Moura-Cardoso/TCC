const int rele = 8;
const int sensor_umidade = A0;
int minuto = 60000;
int valorUmidade = 0;

void setup() {
    Serial.begin(9600);

    pinMode(rele, OUTPUT);
    pinMode(sensor_umidade, INPUT);

    digitalWrite(rele, LOW); //inicia com o rele desligado
    
}

void loop() {
  
  valorUmidade = analogRead(sensor_umidade);

  if(valorUmidade > 600){
    digitalWrite(rele,HIGH);
    Serial.println("Solo seco, iniciando irrigação");
    Serial.println("Valor do sensor de umidade", valorUmidade);
    delay(minuto);
    digitalWrite(rele,LOW);
  }else {
    digitalWrite(rele,LOW);
    Serial.println("Solo umido, impróprio para irrigação");
    Serial.println("Valor do sensor de umidade", valorUmidade);
    
    delay(minuto);
  }

  delay(5000);
    
}

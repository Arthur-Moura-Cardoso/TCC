const int rele = 8;
const int sensor_umidade = A0;
int minuto = 60000;
int valorUmidade = 0;
char ligarSolenoide = LOW;
char desligarSolenoide = HIGH;

void setup() {
    Serial.begin(9600);

    pinMode(rele, OUTPUT);
    pinMode(sensor_umidade, INPUT);

    digitalWrite(rele, desligarSolenoide); //inicia com o rele desligado
    
}

void loop() {
  
  valorUmidade = analogRead(sensor_umidade);

  if(valorUmidade > 600){
    digitalWrite(rele,ligarSolenoide);
    Serial.println("Solo seco, iniciando irrigação");
    Serial.println("Valor do sensor de umidade");
    Serial.println(valorUmidade);
    delay(10000);
    digitalWrite(rele,desligarSolenoide);
  }else {
    digitalWrite(rele,desligarSolenoide);
    Serial.println("Solo umido, impróprio para irrigação");
    Serial.println("Valor do sensor de umidade");
    Serial.println(valorUmidade);
    
    delay(10000);
  }

  Serial.println("Desativando");
  digitalWrite(rele,desligarSolenoide);
  delay(1000);

    
}

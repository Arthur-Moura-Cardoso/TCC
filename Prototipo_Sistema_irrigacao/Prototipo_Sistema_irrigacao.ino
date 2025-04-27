const int rele = 2;

const int sensor_umidade = A0;
int leitura_umidade  = 0;
byte indice_umidade  = 0;

const int sensor_uv = A1;
int leitura_uv = 0;
byte indice_uv = 0;

int minuto = 60000;

void setup() {
  Serial.begin(9600);

  pinMode(sensor_uv, INPUT);
  pinMode(sensor_umidade, INPUT);
  pinMode(rele, OUTPUT);

  digitalWrite(rele, LOW);
}

void loop() {

  leitura_umidade = analogRead(sensor_umidade);
  indice_umidade = map(leitura_umidade, 0 , 1023 , 0 , 10);

  //SERIAL PARA TESTE
  Serial.print(leitura_umidade);
  Serial.println("Valor sensor de umidade bruto");
  Serial.print(indice_umidade);
  Serial.println("Valor sensor de umidade processado");

  leitura_uv = analogRead(sensor_uv);
  indice_uv = map(leitura_uv, 0,203, 0,10);

  //SERIAL PARA TESTE
  Serial.print(leitura_uv);
  Serial.println("Valor sensor uv bruto");
  Serial.print(indice_uv);
  Serial.println("Valor sensor uv processado");

  if(indice_umidade > 5 && indice_uv < 5){
    digitalWrite(rele, HIGH);
    Serial.println("Os raios uv e a umidade estão próprias para a irrigação");
    Serial.println("Ativando valvula solenoide...");

    delay(3*minuto);
    
    digitalWrite(rele, LOW);
    Serial.println("Irrigação concluida");
    Serial.println("Desativando valvula solenoide...");

  }else if (indice_umidade > 5 && indice_uv > 5){
    Serial.println("Solo esta seco porem os raios uv estão elevados");
    Serial.println("Solo impropio para a irrigação");
  }

  delay(1000);

}
// arduino - tm1638
// author - kass-andra-go
// year - 2024

#define SS 10
#define CLK 12
#define DATA_PIN 11

void upload_com(uint8_t data)
{
  digitalWrite(SS,LOW);
  shiftOut(DATA_PIN, CLK, LSBFIRST, data);
  digitalWrite(SS,HIGH);
  _delay_ms(100);
}
void upload_data(uint8_t addr, uint8_t data)
{
    digitalWrite(SS,LOW);
    shiftOut(DATA_PIN, CLK, LSBFIRST, addr);
  shiftOut(DATA_PIN, CLK, LSBFIRST, data);
  digitalWrite(SS,HIGH);
  _delay_ms(100);
}

int main() {
  uint8_t data;
  
  pinMode(CLK, OUTPUT); //clk
  pinMode(DATA_PIN, OUTPUT); //DIO
  pinMode(SS, OUTPUT); //STB

  digitalWrite(SS, HIGH);

  upload_com(0x8b);
  upload_com(0x44);

  upload_data(0xC0, 0x3f);
  upload_data(0xC2, 0x5b);
  upload_data(0xC4, 0x4f);
  upload_data(0xC6, 0x66);
  upload_data(0xC8, 0x6d);
  upload_data(0xCA, 0x7d);
  upload_data(0xCC, 0x7);
  upload_data(0xCE, 0x6f);

while(1){

}
}

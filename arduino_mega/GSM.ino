
const char PHONE_CALL[] = "ATD+ ";
const char HANG_UP[] = "ATH";
const char START_SMS[] = "AT+CMGF=1";
const String SET_SMS_RECEIVER = "AT+CMGS=\"";
const char SEND_SMS = 26;
const String RECEIVERS_PHONE_NUM = "+37060545482";

int sendSMS(String message)
{
    Serial3.println("AT+CMGF=1");
    updateGSM();
    Serial3.println(SET_SMS_RECEIVER + RECEIVERS_PHONE_NUM + "\"");
    updateGSM();
    Serial3.print(message);
    updateGSM();
    Serial3.write(SEND_SMS);
    return 1;
}
int makeCall()
{
    Serial.println("making call");

    Serial3.println("ATD+37060545482;");
    updateGSM();
    delay(20000);
    Serial3.write("ATH");
    updateGSM();
    return 1;
}
void setupGSM()
{
    Serial3.begin(115200, SERIAL_8N1);
    delay(1000);
    Serial3.println("AT");
    updateGSM();
}

void updateGSM()
{
    delay(500);
    while (Serial.available())
    {
        Serial3.write(Serial.read());
    }
    while (Serial3.available())
    {
        Serial.write(Serial3.read());
    }
}
void serialEvent3()
{
    Serial.write(Serial3.read());
}
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#include <HardwareSerial.h>

#include <string.h>

HardwareSerial hSerial(1);


// https://www.uuidgenerator.net/
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
String valor;


class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();

      if (value.length() > 0) {
        valor = "";
        for (int i = 0; i < value.length(); i++) {
          valor = valor + value[i];
        }
        Serial.println("valor = ");
        hSerial.println(valor); // Presenta valor.
      }
    }
};

void setupBluetooth() {

  BLEDevice::init("ESP32");
  /*
     Required in authentication process to provide displaying and/or input passkey or yes/no butttons confirmation
  */
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );
  pCharacteristic->setAccessPermissions(ESP_GATT_PERM_READ_ENCRYPTED | ESP_GATT_PERM_WRITE_ENCRYPTED);
  pCharacteristic->setValue("Hello World says Neil");
  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();

  BLESecurity *pSecurity = new BLESecurity();
  uint32_t passkey = 123456;
  esp_ble_gap_set_security_param(ESP_BLE_SM_SET_STATIC_PASSKEY, &passkey, sizeof(uint32_t));
  pSecurity->setCapability(ESP_IO_CAP_OUT);
  pSecurity->setKeySize();
  pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_ONLY);
  pSecurity->setInitEncryptionKey(ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK);

  //set static passkey
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void setup() {
  Serial.begin(115200);
  hSerial.begin(115200);
  Serial.println("Starting BLE work!");

  setupBluetooth();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
}

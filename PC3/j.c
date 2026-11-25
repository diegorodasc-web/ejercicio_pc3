#include <stdio.h>
enum TipoSensor {
 SENSOR_TEMPERATURA,
 SENSOR_PRESION,
 SENSOR_HUMEDAD
};
union Medicion {
 float temperatura;
 float presion;
 int humedad;
};

struct Sensor {
 int codigo;
 enum TipoSensor tipo;
 union Medicion valor;
};
int main() {
 struct Sensor s;
 s.codigo = 1;
 s.tipo = SENSOR_TEMPERATURA;
 s.valor.temperatura = 25.5;
 if (s.tipo == SENSOR_TEMPERATURA) {
 printf("Temperatura: %.2f\n",
 s.valor.temperatura);
 }
 return 0;
}

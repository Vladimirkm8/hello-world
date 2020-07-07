#include <sysreg.h>
#include <hal_1967VN044.h> // Прототип функции задержки, реализованной ниже
void Delay(int waitTicks);
int main(void)
{
         HAL_SYS_FlagEnable(); // Основной цикл
         while(1) {
                  __builtin_sysreg_write(__FLAGREGST, 0x01); // зажигаем светодиод FLAG0
                  Delay (500000);
                  __builtin_sysreg_write(__FLAGREGCL, 0x00); // гасим светодиод FLAG0
                  __builtin_sysreg_write(__FLAGREGST, 0x02); // зажигаем светодиод FLAG1
                  Delay (500000);
                  __builtin_sysreg_write(__FLAGREGCL, 0x00);
                  __builtin_sysreg_write(__FLAGREGST, 0x04); // зажигаем светодиод FLAG2
                  Delay (500000);
                  __builtin_sysreg_write(__FLAGREGCL, 0x00);
                  __builtin_sysreg_write(__FLAGREGST, 0x08); // зажигаем светодиод FLAG3
                  Delay (500000);
                  __builtin_sysreg_write(__FLAGREGCL, 0x00);
         }
}
//Функция задержки
void Delay(int waitTicks)
{
int i;
for (i = 0; i < waitTicks; i++);
}

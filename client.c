/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:40:08 by bsoykan           #+#    #+#             */
/*   Updated: 2023/10/23 15:52:26 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include "libft/libft.h"



int main(int ac,char **av){
	
	int i;
	int pid;
	int power;
	char *str;

	i = 0;
	power = 128;
	if (ac < 3){
		ft_putstr_fd("ErRor: arguments not enough!!!\n", 2);
		return (-1);
	}
	else if (ac > 3){
		ft_putstr_fd("ErRor: arguments too much!!!\n", 2);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	while (str[i]){
		while (power >= 1){
			if (str[i] & power) //if içerisindeki koda göre gönderim yapar
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			power /= 2;
		usleep(100);
		}
		power = 128;
		i++;
	}
	return (0);
}


/*
örnek: 
ABC
A = 65 = 0b01000001 
B = 66 = 0b01000010
C = 67 = 0b01000011
ilk önce A ile başlanır. A 65 olduğu için 8 kere döner.
A = 0b01000001
ilk önce 128 ile karşılaştırma yapılır en soldaki bit 1 ise sigusr1 gönderilir.
server tarafında alınan sinyal sigusr1 ise 1 ise letter değişkenine power 128 olur
*/


//image.png

/*
her bir karakterin binary karşılığı 8 bit olduğu için 8 kere döndürüyoruz.
str[i] & power ile str[i] nin binary karşılığının power ile and işlemi yapıyoruz.
eğer sonuç 0 ise 0, 1 ise 1 oluyor. 0 ise SIGUSR2, 1 ise SIGUSR1 gönderiyoruz.
power 2 nin 8. kuvvetinden başlıyor ve her döngüde 2 nin bir eksiğine bölünüyor.
yani 128, 64, 32, 16, 8, 4, 2, 1 şeklinde.
örnek:{
str = "A"

str[0] = 'A' = 65 = 0b01000001
power = 128 = 0b10000000
power = 64 = 0b01000000
power = 32 = 0b00100000
power = 16 = 0b00010000
power = 8 = 0b00001000
power = 4 = 0b00000100
power = 2 = 0b00000010
power = 1 = 0b00000001
str[0] & power = 0b01000001 & 0b10000000 = 0b00000000 = 0
kill(pid, SIGUSR2);

bu şekilde her bir bitin ne olduğu açığa çıkar ve bu açığa çıkan bitleri de 
kill fonksiyonu ile göndeririz. server üzerinde de yeniden bit to byte yapılır.
}
┌─────────────┬──────────────┬───────────────┐
│ str[i]      │ power        │ str[i] & power│
├─────────────┼──────────────┼───────────────┤
│   0b00000001│    0b10000000│    0b00000000 │
│   0b00000010│    0b10000000│    0b00000000 │
│   0b00000100│    0b10000000│    0b00000000 │
│   0b00001000│    0b10000000│    0b00000000 │
│   0b00010000│    0b10000000│    0b00000000 │
│   0b00100000│    0b10000000│    0b00000000 │
│   0b01000000│    0b10000000│    0b00000000 │
│   0b10000000│    0b10000000│    0b10000000 │
└────────────┴──────────────┴─────────────── ┘

*/
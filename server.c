/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:01:56 by bsoykan           #+#    #+#             */
/*   Updated: 2023/10/23 15:01:24 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	handler(int signum)
{
	static int	letter;
	static int	power;

	if (!power)
		power = 128;
	if (signum == SIGUSR1) // eğer gelen sinyal SIGUSR1 ise 1 ile kaydırma yapar ve toplar.
		letter += power; // 1 ile kaydırma yapar ve toplar.
	power /= 2; // power = 64, 32, 16, 8, 4, 2, 1 şeklinde çıkartma yapar.
	if (power == 0){ 
		ft_putchar_fd(letter, 1);
		power = 128;
		letter = 0;
	}
}

int	main(void)
{
    ft_putstr_fd("PID: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n", 1);
    signal(SIGUSR1, handler); // her bir bit için program dinleme yapar her bir bit için çalışır ve handler fonksiyonuna gider.
    signal(SIGUSR2, handler); // her bir bit için program dinleme yapar her bir bit için çalışır ve handler fonksiyonuna gider. //statik olmasının sebebi her bir bit için çalışmasıdır.
    while (1)
        pause();
    return (0);
}

/*
`letter` değişkeni her bit için toplanır. İşte bir örnek:

Varsayalım ki `client` tarafından gönderilen 8 bitlik binary bir karakter, "01000001" yani 'A' karakteridir.

1. İşlem: 
   - Başlangıçta `letter = 0`, `power = 128`.
   - İlk bit (en sol bit) 0 olduğu için `signum` değeri `SIGUSR2` olur.
   - Çünkü `signum` değeri `SIGUSR2`, `letter` değeri değişmez (0).
   - `power` değeri 64 olur (`power /= 2`).

2. İşlem: 
   - İkinci bit 1 olduğu için `signum` değeri `SIGUSR1` olur.
   - `letter` değeri 64 ile toplanır (`letter += power`), yani `letter = 64`.
   - `power` değeri 32 olur (`power /= 2`).

3. İşlem: 
   - Üçüncü bit 0 olduğu için `signum` değeri `SIGUSR2` olur.
   - `letter` değeri değişmez (64).
   - `power` değeri 16 olur (`power /= 2`).

Bu işlem devam eder ve tüm 8 bit işlendikten sonra `power` değeri 0 olur ve tam bir karakter (burada 'A') elde edilir. `letter` değişkeni, her bit için sırasıyla işlem yaparak karakterin değerini toplar.
*/
// client 1 karakter için 8 döngü boyunca 1 ve 0 gönderiyor. sonrasında gönderilen bu değerler serverda handler fonksiyonuna gidiyor. 
//bu fonksiyona gelen 0 ve 1 değerleri letter denilen değişkende toplanarak ortaya bitlerden toplanan bir karakter ortaya çıkıyor
//tüm bitler bittikten sonra power 0 olur. fakat letter 0 olmadığı için ilk karakteri yazdırır tekrardan döngü devam eder. 
//son seviyede sinyaller hep 0 olacağı için letter de 0 olur ve fonskiyondan çıkılarak program sonlanır.




# Push_swap Projesi

Bu proje, sıralı olmayan bir dizi sayıyı sıralı hale getirmek için iki farklı yığın (stack) veri yapısı kullanarak çözümlemeyi amaçlamaktadır. Push_swap, 42 Network programlama okulu için bir proje olarak geliştirilmiştir.

## Başlangıç

Bu talimatlar, projenin yerel makinenizde nasıl çalıştırılacağını ve kullanılacağını açıklar. Başlamadan önce, projeyi yerel makinenizde çalıştırmak için bir C derleyicisine (örneğin, GCC) ihtiyacınız olacaktır.

1. Projeyi klonlayın:

```bash
git clone https://github.com/sizin-github-hesabınız/push_swap.git
cd push_swap

Push_swap'i derleyin
make

Kullanım

Proje, iki ayrı komut satırı programı içerir: push_swap ve checker.

push_swap

push_swap programı, verilen bir dizi sayıyı sıralamak için gereken hareketleri hesaplayan ana programdır. Aşağıdaki komutu kullanarak çalıştırabilirsiniz:

./push_swap [sayılar]
./push_swap 3 2 1

checker

checker programı, push_swap tarafından üretilen hareketleri doğrulamak için kullanılır. push_swap tarafından hesaplanan hareketleri kontrol etmek için aşağıdaki komutu kullanabilirsiniz:

./push_swap [sayılar] | ./checker [sayılar]

Katkıda Bulunma

Bu proje, açık kaynaklı bir projedir ve katkıda bulunmaktan çekinmeyin. Her türlü katkı ve önerileri memnuniyetle karşılıyoruz. Katkıda bulunmak isterseniz, lütfen aşağıdaki adımları izleyin:

    Bu projeyi fork edin.
    Yeni bir özellik eklemek veya hata düzeltmek için bir dal (branch) oluşturun.
    Değişikliklerinizi yapın ve commit'leyin.
    Yaptığınız değişiklikleri fork ettiğiniz orijinal depoya (upstream repository) gönderin.
    Bir pull isteği (pull request) oluşturun ve değişikliklerinizi değerlendirmemizi bekleyin.

Lisans

Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına başvurun.

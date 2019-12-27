Repository to do some tests with FFI

PHP 8.0.0-dev cli NTS, on Debian Buster 10



```
apt-get install libldap2-dev libldap-2.4-2 libtool-bin lbzip2 libxml2-dev bzip2 re2c libbz2-dev apache2-dev libjpeg-dev libxpm-dev libxpm-dev libgmp-dev libgmp3-dev libmcrypt-dev libpspell-dev librecode-dev libcurl4-openssl-dev libxft-dev
```

Download or clone master php-src

```
$ ./buildconf
$ ./configure --with-ffi
$ make cli -j 8
$ sapi/cli/php -v
PHP 8.0.0-dev (cli) (built: Dec 20 2019 22:41:23) ( NTS )
Copyright (c) The PHP Group
Zend Engine v3.4.0-dev, Copyright (c) Zend Technologies
```

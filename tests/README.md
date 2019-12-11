Repository to do some tests with FFI

Tested with PHP 7.4.0-dev (Last 7.4 git tag), on Debian Buster 10



```
apt-get install libldap2-dev libldap-2.4-2 libtool-bin lbzip2 libxml2-dev bzip2 re2c libbz2-dev apache2-dev libjpeg-dev libxpm-dev libxpm-dev libgmp-dev libgmp3-dev libmcrypt-dev libpspell-dev librecode-dev libcurl4-openssl-dev libxft-dev
```

```
$ ./buildconf
$ ./configure --with-ffi
$ make cli -j 8
$ sapi/cli/php -v
PHP 7.4.0-dev (cli) (built: Jul 25 2019 09:08:48) ( NTS )
Copyright (c) The PHP Group
Zend Engine v3.4.0-dev, Copyright (c) Zend Technologies
```

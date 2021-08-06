FROM centos:7.6.1810

MAINTAINER neeky@live.com
#QQ:1721900707
#WeChat: jianglegege
ENV LANG zh_CN.UTF-8

WORKDIR /tmp/

RUN set -ex \
    && yum -y install gcc gcc-c++ libffi libyaml-devel libffi-devel zlib zlib-devel openssl shadow-utils \
    openssl-devel libyaml sqlite-devel libxml2 libxslt-devel libxml2-devel wget vim mysql-devel automake ncurses-devel \
    && yum clean all 

ADD . /tmp/

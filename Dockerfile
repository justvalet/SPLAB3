FROM centos
COPY dsn.c .
RUN yum install -y glibc-langpack-en
RUN yum install gcc -y

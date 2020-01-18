FROM nginx:latest
COPY index.html /var/www/html
RUN  ln -sf /dev/stdout /var/log/nginx/access.log && ln -sf /dev/stderr /var/log/nginx/error.log

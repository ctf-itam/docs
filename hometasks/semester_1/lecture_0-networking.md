# Lecture 0: Networking / Homework

## Docker networking basics

### Read the [documentation](https://docs.docker.com/engine/reference/run/)!

Always consult *the documentation* if you have any questions. Alternatively, consult `man`.

1. Run a container with `nginx` image and expose its port 80 to the host under port 8040.
2. Visit the webpage in any browser under `<local IP or DNS name>:8040`.
3. Get to know you container's internal IP address (typically starting with 172.<...>): `docker inspect <container ID> | grep IPAddress`.
4. Visit the webpage in any browser under `<container IP>:80`.
5. Explain why this is possible and what is the difference between the two approaches.
6. Stop and remove the container (see the official documentation; link above).
7. Create a `docker-compose.yml` file under a folder named `nginx-test` and create it using the following syntax:
    ```yaml
    ---
    version: '3.7'
    services:
      nginx:
        image: nginx
        ports:
          - 8040:80
        ...
    ```
8. Assign a static IP to the container using the top-level `networks`, `ipam/config/subnet` and `<custom_network>/ipv4_address` directives. Use `/26` netmask.
9. Execute `docker-compose up -d` and visit the webpage in any browser under `<container IP>:80`.

## Questions

1. Explain what happens if you assign the container a port that's already been assigned (you never ran `docker stop <CID>`)
2. Explain what is a subnet and what is a netmask.
3. Provide all local subnet address ranges.
4. What is the difference between `network_mode: host` and forwarding all required porta manually?

## Rules

1. You can use any resources you want.
2. You may and should ask questions in the chat.
3. You must not submit your answers to the chat.
4. You must send your answers to [@oxb1b1](https://t.me/oxb1b1) via Telegram
5. You may use any language in your homework, programming or not.

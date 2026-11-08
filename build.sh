export ENV_UID=$(id -u)
export ENV_GID=$(id -g)
docker compose run --rm cpp cmake --preset linux-debug
docker compose run --rm cpp cmake --build --preset linux-debug
#docker compose run --rm cpp ctest --preset linux-debug



#docker compose exec cpp cmake --preset windows-release 
#docker compose exec cpp cmake --build --preset windows-release


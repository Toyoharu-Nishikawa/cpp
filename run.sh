export ENV_UID=$(id -u)
export ENV_GID=$(id -g)
docker compose run --rm cpp ./build/linux/debug/run 



#docker compose exec cpp cmake --preset windows-release 
#docker compose exec cpp cmake --build --preset windows-release


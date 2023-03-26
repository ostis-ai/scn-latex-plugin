java -jar ../thirdparty/antlr/antlr4-4.7.1-complete.jar -Dlanguage=Cpp -no-listener -no-visitor -o ./ ../src/grammar/SCnTex.g4
APP_ROOT_PATH=$(cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && cd .. && pwd)
cmake -B ${APP_ROOT_PATH}/build ${APP_ROOT_PATH} $@
cmake --build ${APP_ROOT_PATH}/build -j$(nproc)

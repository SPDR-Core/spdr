### Building Spider OS X Qt Wallet

1. Ensure you have git installed
    
    ```shell
    brew install git
    ```
2. Clone spdr repository
    
    ```shell
    git clone https://github.com/SPDR-Core/spdr
    ```

3. Ensure mysql and boost installed.
    
    ```shell
    brew install mysql boost
    ```

4. Ensure python 2.7 installed and in your path.

    ```shell
    python --version
    ```

5. Export the required environment variables

    ```shell
    export SPDR_PLATFORM='mac'
    export CXX=clang++
    export CC=clang
    ```

6. Run your build commands

    ```shell
    ./building/common.sh
    ./building/mac/requirements.sh
    ./building/mac/build.sh
    ```
    
8. Create the `.dmg` file

    ```shell
    ./building/mac/dist.sh
    ```


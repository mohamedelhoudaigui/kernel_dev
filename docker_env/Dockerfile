# Use the official Debian base image
FROM randomdude/gcc-cross-x86_64-elf

# Update package lists, install updates, git, and qemu
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install -y git qemu-utils 
RUN apt install -y qemu-system-x86 nano nasm xorriso
RUN	apt install -y grub-pc-bin grub-common
RUN apt-get clean

# Clone the git repository into the home directory
# Replace <repository_url> with the actual URL of the Git repository you want to clone
RUN git clone https://github.com/mohamedelhoudaigui/kernel_dev.git /home/repo

# Set the working directory to the cloned repository
WORKDIR /home/repo

# Default command to run when the container starts
CMD ["/bin/bash"]


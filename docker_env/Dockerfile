# Use the official Debian base image
FROM debian:latest

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists, install updates, git, and qemu
RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get install -y git qemu-utils qemu-system-x86 nano nasm && \
    apt-get clean

# Clone the git repository into the home directory
# Replace <repository_url> with the actual URL of the Git repository you want to clone
RUN git clone https://github.com/mohamedelhoudaigui/kernel_dev.git /home/repo

# Set the working directory to the cloned repository
WORKDIR /home/repo

# Default command to run when the container starts
CMD ["/bin/bash"]


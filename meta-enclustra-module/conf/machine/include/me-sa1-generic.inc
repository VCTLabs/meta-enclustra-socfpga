MACHINEOVERRIDES:prepend = "enclustra:me-sa1-generic:"

require conf/machine/include/socfpga.inc

UBOOT_CONFIG ??= "sdmmc"
UBOOT_CONFIG[sdmmc] = "socfpga_enclustra_mercury_sa1_mmc_defconfig"
UBOOT_CONFIG[emmc]  = "socfpga_enclustra_mercury_sa1_mmc_defconfig"
UBOOT_CONFIG[qspi]  = "socfpga_enclustra_mercury_sa1_qspi_defconfig"

KERNEL_IMAGETYPE = "uImage"
UBOOT_LOADADDRESS = "0x00008000"
UBOOT_ENTRYPOINT = "0x00008000"
# required to build uImage
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_LOADADDRESS}"

IMAGE_FSTYPES = "cpio.gz.u-boot tar.gz wic.bmap"

EXTRA_IMAGEDEPENDS += "\
    device-tree \
    u-boot-socfpga \
    exported-binaries \
"

IMAGE_BOOT_FILES ?= " \
    devicetree.dtb \
    boot.scr \
    fpga.rbf \
    ${KERNEL_IMAGETYPE} \
"

SERIAL_CONSOLES ?= "115200;ttyS0"

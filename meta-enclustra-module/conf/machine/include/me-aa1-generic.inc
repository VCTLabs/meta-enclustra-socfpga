MACHINEOVERRIDES:prepend = "enclustra:me-aa1-generic:"

require conf/machine/include/socfpga.inc

SPL_BINARY = "spl/u-boot-splx4.sfp"
UBOOT_BINARY = "u-boot.img"

UBOOT_CONFIG ??= "sdmmc"
UBOOT_CONFIG[sdmmc] = "socfpga_enclustra_mercury_aa1_defconfig"
UBOOT_CONFIG[emmc]  = "socfpga_enclustra_mercury_aa1_defconfig"
UBOOT_CONFIG[qspi] = "socfpga_enclustra_mercury_aa1_defconfig"

KERNEL_IMAGETYPE = "uImage"
UBOOT_LOADADDRESS = "0x00008000"
UBOOT_ENTRYPOINT = "0x00008000"
# required to build uImage
KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_LOADADDRESS}"

IMAGE_FSTYPES = "cpio.gz.u-boot wic.bmap tar.gz"

EXTRA_IMAGEDEPENDS += "\
    device-tree \
    u-boot-socfpga \
    exported-binaries \
"

## NB: use boot.scr due to common u-boot environment, even if there
## are other variables for u-boot.scr around:
##     boot_scripts=boot.scr.uimg boot.scr
IMAGE_BOOT_FILES ?= " \
    devicetree.dtb \
    socfpga_enclustra_mercury_emmc_overlay.dtbo \
    socfpga_enclustra_mercury_qspi_overlay.dtbo \
    socfpga_enclustra_mercury_sdmmc_overlay.dtbo \
    boot.scr \
    bitstream.itb \
    ${UBOOT_BINARY} \
    ${KERNEL_IMAGETYPE} \
"

SERIAL_CONSOLES ?= "115200;ttyS0"

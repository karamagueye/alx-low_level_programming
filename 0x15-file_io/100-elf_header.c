#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void print_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void display_elf_header(const Elf64_Ehdr *header) {
    int i;
    int elf_class, data_encoding, osabi, elf_type;
    
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < 16; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < 15) printf(" ");
    }
    printf("\n");

    printf("  Class:                             ");
    elf_class = header->e_ident[EI_CLASS];
    switch (elf_class) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            print_error("Invalid ELF class");
    }

    printf("  Data:                              ");
    data_encoding = header->e_ident[EI_DATA];
    switch (data_encoding) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            print_error("Invalid data encoding");
    }

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    osabi = header->e_ident[EI_OSABI];
    switch (osabi) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - GNU/Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        default:
            printf("<unknown: %d>\n", osabi);
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    elf_type = header->e_type;
    switch (elf_type) {
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        default:
            printf("Other (%d)\n", elf_type);
    }

    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    const char *filename;
    int fd;
    Elf64_Ehdr header;
    
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error(strerror(errno));
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        print_error("Error reading ELF header");
    }

    
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    display_elf_header(&header);

    close(fd);
    return 0;
}


# WASX: Windows ARM Subsystem for XNU

**WASX** is a compatibility layer designed to run **Mach-O binaries** (from macOS, iOS, iPadOS) on **Windows ARM64** devices. Inspired by Wine and Rosetta 2, WASX aims to provide a **POSIX/XNU-compatible environment** on top of Windows.

---

## 🎯 Project Goals

- ✅ **Run Mach-O ARM64 binaries** on Windows ARM64
- ✅ **Translate** key system calls and interfaces from **XNU/POSIX** to Windows equivalents
- ✅ Focus on **user-mode translation only** (no kernel-mode emulation)
- ⚠️ No intention to support x86_64 apps (aligns with Apple deprecation of x86)
- ✅ Designed for **performance-critical code** with optional native C++ integration

---

## 🧱 Architecture Overview

```
Mach-O Binary (ARM64)
       ↓
 [WASX Runtime Layer]
       ↓
POSIX/XNU Interface → Windows API Shims
       ↓
  Windows ARM64 (User Mode)
```

---

## 🔧 Components

- **Binary Loader**
  - Parses Mach-O headers
  - Maps segments into memory
  - Prepares environment (dyld-style if needed)

- **Syscall Translator**
  - Maps POSIX/XNU syscalls (e.g., `fork`, `open`, `mmap`) to Win32 equivalents or emulated behavior

- **Libc Wrapper**
  - Custom POSIX-compatible libc layer, based on Musl or minimalist implementation

- **Dynamic Linker Support**
  - Reimplements parts of `dyld` to handle dynamic loading

- **Translator (like Rosetta)**
  - Optional: Future plan to implement JIT or binary translation (e.g., `CoreFoundation` stubs, Swift runtime)

---

## 📦 Compatibility Targets

- **OS APIs:** iOS / macOS userland interfaces
- **Binaries:** ARM64 Mach-O apps (e.g., command-line tools, frameworks)
- **Architecture:** Focus on ARMv8/AArch64 only

---

## 🚫 Out of Scope

- ❌ No x86_64 support
- ❌ No kernel-mode drivers or kexts
- ❌ Not a full virtual machine or hypervisor

---

## 🗓️ Roadmap (Tentative)

| Milestone                  | Status       |
|---------------------------|--------------|
| Project scaffold + loader | 🛠 In progress |
| POSIX syscall layer       | 🛠 In progress |
| Basic libc support        | 🛠 In progress |
| Dynamic linker prototype  | 🧪 Planned     |
| App compatibility testing | 🚧 Planned     |

---

## 💡 Inspirations

- [Wine](https://www.winehq.org/): Windows API on POSIX
- [Rosetta 2](https://support.apple.com/en-us/HT211861): x86_64 to ARM64 binary translation
- [Darling](https://www.darlinghq.org/): macOS on Linux compatibility layer
- [WSL](https://learn.microsoft.com/en-us/windows/wsl/): Linux on Windows subsystem
# Polling-enhanced firmware / 轮询增强固件

## Scope / 适用范围

This is a Chameleon Ultra firmware variant based on upstream `v2.2.0`. Its main addition is automatic LF/HF polling for the active slot. It is intended only for tags, devices, and systems you own or are explicitly authorized to test.

本固件基于上游 `v2.2.0`。核心功能是为当前活动槽位提供自动 LF/HF 轮询。请仅在你拥有或获得明确授权测试的标签、设备和系统上使用。

## Improvements over upstream v2.2.0 / 相比原版 v2.2.0 的优化

- **Automatic active-slot polling / 自动槽位轮询.** Adds configurable automatic polling for the active slot, so LF/HF tag emulation state can be detected and managed without repeatedly issuing manual polling commands.

- **Exclusive LF/HF sensing during slot changes / 槽位切换时的 LF/HF 独占检测.** Coordinates LF and HF sensing during slot transitions to reduce conflicting state changes while the selected slot is updated.

- **Persistent configuration with migration / 可持久化配置与迁移.** Adds the slot-poll setting to device settings, bumps the settings schema to version 7, and includes migration logic for existing installations.

- **CLI control / 命令行控制.** Adds `hw settings slotpoll` to the official CLI scripts for checking and changing the slot-poll setting.

- **HF session-state robustness / HF 会话状态可靠性.** Marks the relevant HF session state as `volatile` so concurrent firmware paths observe current state correctly.

- **Broader EM410X handling / 更完整的 EM410X 处理.** Adds handling for 16-bit, 32-bit, and 64-bit EM410X data variants.

- **More resilient local builds / 更稳健的本地构建.** Improves the build script shebang and provides a `mergehex` fallback path when the expected tool location is unavailable.

## Verification completed / 已完成验证

- Full Chameleon Ultra firmware build completed successfully.
- Firmware image was flashed to a connected Chameleon Ultra.
- The new `get_slot_poll()` protocol command returned successfully and reported polling enabled.
- `git diff --check` and `bash -n firmware/build.sh` passed before the firmware commit.

These checks confirm the build, flash, and protocol/configuration path. They do not replace testing with the specific authorized LF/HF readers, cards, and environments in which you intend to use the firmware.

以上验证覆盖完整构建、刷写及协议/配置路径；不等同于对你实际授权使用场景中的读卡器、卡片和环境完成全部兼容性验证。

## Firmware commit / 固件提交

- Firmware feature commit: `8fd9d73 feat: add automatic slot polling`
- Branch: `feature/slot-polling-final`

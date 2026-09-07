{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs =
    { nixpkgs, ... }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
        "aarch64-darwin"
        "x86_64-darwin"
      ];
      forAllSystems = f: nixpkgs.lib.genAttrs systems (system: f nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShellNoCC {
          packages = with pkgs; [
            qmk
            gnumake
            git
            python3
            gcc-arm-embedded
            picotool
          ];

          shellHook = ''
            export QMK_HOME="$PWD"

            # qmk propagates the avr toolchain
            unset CC CXX CPP AR AS LD NM OBJCOPY OBJDUMP RANLIB READELF SIZE STRINGS STRIP
          '';
        };
      });
    };
}

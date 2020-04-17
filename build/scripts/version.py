from __future__ import annotations

import configparser
import os

class Version:
    def __init__(self, major: int, minor: int, patch: int) -> None:
        self.major = major
        self.minor = minor
        self.patch = patch

    @staticmethod
    def _version_file_path(directory):
        return os.path.join(directory, 'version.ini')

    @staticmethod
    def load_version(directory: str) -> Version:
        config = configparser.ConfigParser()
        config.read(Version._version_file_path(directory))
        version = config['VERSION']
        return Version(
            int(version['major']),
            int(version['minor']),
            int(version['patch']))

    def as_map(self):
        return {"major": self.major, "minor": self.minor, "patch": self.patch}


def get_version_text(version):
    return F"v.{version['major']}.{version['minor']}.{version['patch']}"


def get_version_without_v(version_string):
    return version_string.replace("v.", "")


def update_major(version):
    return create_version(get_major(version) + 1, 0, 0)


def update_minor(version):
    return create_version(get_major(version), get_minor(version) + 1, 0)


def update_patch(version):
    return create_version(get_major(version), get_minor(version), get_patch(version) + 1)


def get_major(version):
    return int(version['major'])


def get_minor(version):
    return int(version['minor'])


def get_patch(version):
    return int(version['patch'])


def no_version_change(version):
    # This is useful if a deploy failed part-way through, and we don't want to increment the version number
    return create_version(get_major(version), get_minor(version), get_patch(version))


def load_version(directory):
    return Version.load_version(directory).as_map()


def create_version(major, minor, patch):
    return Version(major, minor, patch).as_map()


def write_version(version, directory):
    config = configparser.ConfigParser()
    config['VERSION'] = version

    with open(Version._version_file_path(directory), 'w') as configfile:
        config.write(configfile)

# Generated by Django 2.2.10 on 2020-04-08 08:03

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('kubeops_api', '0074_auto_20200316_0650'),
    ]

    operations = [
        migrations.AddField(
            model_name='package',
            name='state',
            field=models.CharField(choices=[('offline', 'offline'), ('online', 'online')], default='offline', max_length=32),
        ),
        migrations.AlterField(
            model_name='host',
            name='status',
            field=models.CharField(choices=[('RUNNING', 'running'), ('CREATING', 'creating'), ('UNKNOWN', 'unknown'), ('UPDATING', 'updating')], default='UNKNOWN', max_length=128),
        ),
    ]
